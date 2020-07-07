#!/bin/bash
## with bag or sim running
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)
ROS_NAMESPACE=scout_1/camera rosrun stereo_image_proc stereo_image_proc &
rosrun topic_tools transform /scout_1/camera/left/camera_info /scout_1/camera/left/camera_infoNew sensor_msgs/CameraInfo  'sensor_msgs.msg.CameraInfo(header=m.header,distortion_model=m.distortion_model,D=m.D,K=m.K,R=m.R,P=[381.36246688113556, 0.0, 320.5, 0.0, 0.0, 381.36246688113556, 240.5, 0.0, 0.0, 0.0, 1.0, 0.0],binning_x=m.binning_x,binning_y=m.binning_y,roi=m.roi)' --import sensor_msgs std_msgs &
# rosrun rtabmap_ros stereo_odometry
