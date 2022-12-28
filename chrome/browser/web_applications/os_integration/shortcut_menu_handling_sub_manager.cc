// Copyright 2022 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/web_applications/os_integration/shortcut_menu_handling_sub_manager.h"

#include <utility>

#include "chrome/browser/web_applications/proto/web_app_os_integration_state.pb.h"
#include "chrome/browser/web_applications/web_app.h"
#include "chrome/browser/web_applications/web_app_registrar.h"

namespace web_app {
ShortcutMenuHandlingSubManager::ShortcutMenuHandlingSubManager(WebAppIconManager& icon_manager): icon_manager_(icon_manager) {}

ShortcutMenuHandlingSubManager::~ShortcutMenuHandlingSubManager() = default;

void ShortcutMenuHandlingSubManager::Start() {}

void ShortcutMenuHandlingSubManager::Shutdown() {}

void ShortcutMenuHandlingSubManager::Configure(const AppId& app_id,
                         proto::WebAppOsIntegrationState& desired_state,
                         base::OnceClosure configure_done) {
    icon_manager_->ReadAllShortcutMenuIconsWithTimestamp(app_id, );
}

void ShortcutMenuHandlingSubManager::Execute(
      const AppId& app_id,
      const proto::WebAppOsIntegrationState& desired_state,
      const absl::optional<proto::WebAppOsIntegrationState>& current_state,
      base::OnceClosure callback) {}

}  // namespace web_app