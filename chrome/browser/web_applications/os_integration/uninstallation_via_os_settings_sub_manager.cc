// Copyright 2022 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/web_applications/os_integration/uninstallation_via_os_settings_sub_manager.h"

#include <memory>
#include <utility>

#include "base/containers/flat_map.h"
#include "base/functional/bind.h"
#include "base/strings/utf_string_conversions.h"
#include "chrome/browser/web_applications/proto/web_app_os_integration_state.pb.h"
#include "chrome/browser/web_applications/web_app.h"
#include "chrome/browser/web_applications/web_app_constants.h"
#include "chrome/browser/web_applications/web_app_icon_manager.h"
#include "chrome/browser/web_applications/web_app_install_info.h"
#include "chrome/browser/web_applications/web_app_proto_utils.h"
#include "chrome/browser/web_applications/web_app_registrar.h"

namespace web_app {

UninstallationViaOsSettingsSubManager::UninstallationViaOsSettingsSubManager(
    WebAppRegistrar& registrar)
    : registrar_(registrar) {}

UninstallationViaOsSettingsSubManager::
    ~UninstallationViaOsSettingsSubManager() = default;

void UninstallationViaOsSettingsSubManager::Configure(
    const AppId& app_id,
    proto::WebAppOsIntegrationState& desired_state,
    base::OnceClosure configure_done) {
  const WebApp* web_app = registrar_->GetAppById(app_id);
  if (!web_app) {
    std::move(configure_done).Run();
    return;
  }

  desired_state.set_is_os_registration_required(
      web_app->CanUserUninstallWebApp());
}

void UninstallationViaOsSettingsSubManager::Start() {}

void UninstallationViaOsSettingsSubManager::Shutdown() {}

void UninstallationViaOsSettingsSubManager::Execute(
    const AppId& app_id,
    const proto::WebAppOsIntegrationState& desired_state,
    const absl::optional<proto::WebAppOsIntegrationState>& current_state,
    base::OnceClosure callback) {
  NOTREACHED() << "Not yet implemented";
}

}  // namespace web_app
