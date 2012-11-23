/*
 * get_rviz_camera_position.cpp
 *
 *  Created on: Nov 23, 2012
 *      Author: goa-sn
 */
#include <cob_3d_mapping_rviz_plugins/get_rviz_camera_position.h>

namespace rviz
{
  GetRvizCameraPosition::GetRvizCameraPosition(VisualizationManager* manager )
  : ViewContrller()
  {
     ogre_camera_ = view_controller_->getCamera();

     tf_filter_.connectInput(sub_);
     tf_filter_.registerCallback(boost::bind(&ShapeDisplay::getCamPose, this, _1));

     rviz_camera_position_pub_ = nh_.advertise<geometry_msgs::Pose> ("rviz/camera_position", 1);
  }

  GetRvizCameraPosition::~GetRvizCameraPosition()
  {
  }


  static inline geometry_msgs::Point pointOgreToMsg(const Ogre::Vector3 &o)
  {
    geometry_msgs::Point m;
    m.x = o.x; m.y = o.y; m.z = o.z;
    return m;
  }

  void getCamPose() {

  QVariant target_frame = source_view->subProp( "Target Frame" )->getValue();
      if( target_frame.isValid() )
      {

      Ogre::Vector3 position = ogre_camera_->getPosition();
      Ogre::Quaternion orientation = ogre_camera_->getOrientation();

      geometry_msgs::Point camPosition    = pointOgreToMsg(position) ;
      geometry_msgs::Pose camPose ;

      camPose.position.x = Point.x ;
      camPose.position.y = Point.y ;
      camPose.position.z = Point.z ;

      rviz_camera_position_pub_.publish(camPose) ;


  }
  }






}
