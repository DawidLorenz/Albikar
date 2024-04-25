/**
 * ************************************************************************
 * @copyright Copyright (c) 2024 Dawid Lorenz Development
 * ************************************************************************
 */

#include "QUIApplication.h"

#include <Logger.h>

#include <QQmlApplicationEngine>
#include <QGuiApplication>

namespace albikar::gui {
QUIApplication::QUIApplication(int& argc, char** argv) {
  LOG_INFO("Create QUIApplication");
  int copy_argc = argc;
  qt_qui_app_ = std::make_unique<QGuiApplication>(copy_argc, nullptr);
}

QUIApplication::~QUIApplication() {
  LOG_INFO("Destroy QUIApplication");
}

auto QUIApplication::Start() -> void {
  LOG_INFO("Start QUIApplication");
  const QUrl url(QStringLiteral("qrc:/main.qml"));

  QQmlApplicationEngine engine;
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &*qt_qui_app_,
      [url](QObject* obj, const QUrl& objUrl) {
        if (!obj && url == objUrl) {
          QCoreApplication::exit(-1);
        }
      },
      Qt::QueuedConnection);
  engine.load(url);

  if (engine.rootObjects().isEmpty()) {
    LOG_ERR("Cannot create qt engine");
  }

  qt_qui_app_->exec();
}

auto QUIApplication::Stop() -> void {
  LOG_INFO("Stop QUIApplication");
}
};  // namespace albikar::gui