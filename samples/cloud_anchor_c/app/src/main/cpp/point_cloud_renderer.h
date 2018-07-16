/*
 * Copyright 2017 Google Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef C_ARCORE_CLOUD_ANCHOR_POINT_CLOUD_RENDERER_H_
#define C_ARCORE_CLOUD_ANCHOR_POINT_CLOUD_RENDERER_H_

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <android/asset_manager.h>
#include <cstdlib>
#include <vector>

#include "arcore_c_api.h"
#include "glm.h"

namespace cloud_anchor {

class PointCloudRenderer {
 public:
  // Default constructor of PointCloudRenderer.
  PointCloudRenderer() = default;

  // Default deconstructor of PointCloudRenderer.
  ~PointCloudRenderer() = default;

  // Initialize the GL content, needs to be called on GL thread.
  void InitializeGlContent(AAssetManager* asset_manager);

  // Render the AR point cloud.
  //
  // @param mvp_matrix, the model view projection matrix of point cloud.
  // @param ar_session, the session that is used to query point cloud points
  //     from ar_point_cloud.
  // @param ar_point_cloud, point cloud data to for rendering.
  void Draw(glm::mat4 mvp_matrix, ArSession* ar_session,
            ArPointCloud* ar_point_cloud) const;

 private:
  GLuint shader_program_;
  GLuint attribute_vertices_;
  GLuint uniform_mvp_mat_;
  GLint uniform_color_;
  GLint uniform_point_size_;
};
}  // namespace cloud_anchor

#endif  // C_ARCORE_CLOUD_ANCHOR_POINT_CLOUD_RENDERER_H_
