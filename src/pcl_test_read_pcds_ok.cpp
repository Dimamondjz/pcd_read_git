#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

#include <iostream>

int main(int argc, char** argv) {
  //创建了一个名为cloud的指针，储存XYZ类型的点云数据
  /// home/jz/map_save/10_0_0.pcd
  pcl::PointCloud<pcl::PointXYZ> cloud;
  pcl::PointCloud<pcl::PointXYZ> save_cloud;
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_1(
      new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_0(
      new pcl::PointCloud<pcl::PointXYZ>);
  //*打开点云文件
  if (pcl::io::loadPCDFile<pcl::PointXYZ>("/home/jz/map_save/10_0_0.pcd",
                                          *cloud_0) == -1) {
    PCL_ERROR("Couldn't read file cloud2.pcd\n");
    return (-1);
  }
  if (pcl::io::loadPCDFile<pcl::PointXYZ>("/home/jz/map_save/10_0_10.pcd",
                                          *cloud_1) == -1) {
    PCL_ERROR("Couldn't read file cloud2.pcd\n");
    return (-1);
  }
  std::cout << "-1-------" << std::endl;

  for (auto it = cloud_0->begin(); it != cloud_0->end(); it++) {
    save_cloud.push_back({it->x, it->y, it->z});
  }
  for (auto it = cloud_1->begin(); it != cloud_1->end(); it++) {
    save_cloud.push_back({it->x, it->y, it->z});
  }

  std::cout << "----------------------------" << std::endl;

  pcl::visualization::CloudViewer viewer("cloud viewer");
  viewer.showCloud(save_cloud.makeShared());
  while (!viewer.wasStopped()) {
  }
  //   　　  //也可以使用以下的语句
  //       for (const auto& point : *cloud) {
  //     std::cout << "    " << point.x << " " << point.y << " " << point.z
  //               << std::endl;
  //   }
  return 0;
}