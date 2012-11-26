/*
 * get_rviz_camera_position.h
 *
 *  Created on: Nov 23, 2012
 *      Author: goa-sn
 */

#ifndef GET_RVIZ_CAMERA_POSITION_H_
#define GET_RVIZ_CAMERA_POSITION_H_

#include "rviz/visualization_manager.h"
#include "rviz/view_controller.h"

#include <cob_3d_mapping_msgs/Shape.h>
#include <cob_3d_mapping_msgs/ShapeArray.h>
#include <message_filters/subscriber.h>
#include <tf/message_filter.h>

namespace rviz {


  class GetRvizCameraPosition : public ViewController
  {
    public:
    //Constructor
    GetRvizCameraPosition(rviz::VisualizationManager* manager);
    //Destructor
    ~GetRvizCameraPosition()
      {
       //
      }

    geometry_msgs::Point pointOgreToMsg(const Ogre::Vector3 &o);
    void getCamPose(ViewController* source_view);


    protected:
    Ogre::Camera* ogre_camera_;
    ros::Publisher rviz_camera_position_pub_;
    ros::NodeHandle nh_;
    message_filters::Subscriber<cob_3d_mapping_msgs::ShapeArray> sub_;
    tf::MessageFilter<cob_3d_mapping_msgs::Shape> tf_filter_;
  };
}
#endif /* GET_RVIZ_CAMERA_POSITION_H_ */
