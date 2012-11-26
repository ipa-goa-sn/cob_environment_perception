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
     tf_filter_.registerCallback(boost::bind(&GetRvizCameraPosition::getCamPose, this, _1));

     rviz_camera_position_pub_ = nh_.advertise<geometry_msgs::Pose> ("rviz/camera_position", 1);
  }


  geometry_msgs::Point GetRvizCameraPosition::pointOgreToMsg(const Ogre::Vector3 &o)
  {
    geometry_msgs::Point m;
    m.x = o.x; m.y = o.y; m.z = o.z;
    return m;
  }

  void GetRvizCameraPosition::getCamPose(ViewController* source_view) {

//  QVariant target_frame = source_view->subProp( "Target Frame" )->getValue();
//      if( target_frame.isValid() )
//      {

      Ogre::Vector3 position = ogre_camera_->getRealPosition();            //Gets the real world position of the camera
      Ogre::Quaternion orientation = ogre_camera_->getRealOrientation();   //Gets the real world orientation of the camera

      geometry_msgs::Pose camPose ;

      camPose.position.x = position.x ;
      camPose.position.y = position.y ;
      camPose.position.z = position.z ;

      camPose.orientation.x = orientation.x ;
      camPose.orientation.y = orientation.y ;
      camPose.orientation.z = orientation.z ;


      rviz_camera_position_pub_.publish(camPose) ;


//  }
  }






}
