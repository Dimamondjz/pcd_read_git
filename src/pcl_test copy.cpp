#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

#include <iostream>

int main(int argc, char** argv) {
  //创建了一个名为cloud的指针，储存XYZ类型的点云数据
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
  //*打开点云文件
  if (pcl::io::loadPCDFile<pcl::PointXYZ>("/home/jz/map_save/30_0_0.pcd",
                                          *cloud) == -1) {
    PCL_ERROR("Couldn't read file rabbit.pcd\n");
    return (-1);
  }
  std::cout << "Loaded:" << cloud->width * cloud->height
            << "data points from test_pcd.pcd with the following fields:"
            << std::endl;
  //输出点云数据
  for (size_t i = 0; i < cloud->points.size(); ++i) {
    std::cout << "      " << cloud->points[i].x << "   " << cloud->points[i].y
              << "   " << cloud->points[i].z << "   " << std::endl;
  }
  pcl::visualization::CloudViewer viewer("cloud viewer");
  viewer.showCloud(cloud);
  while (!viewer.wasStopped()) {
  }
  //   　　  //也可以使用以下的语句
  //       for (const auto& point : *cloud) {
  //     std::cout << "    " << point.x << " " << point.y << " " << point.z
  //               << std::endl;
  //   }
  return 0;
}