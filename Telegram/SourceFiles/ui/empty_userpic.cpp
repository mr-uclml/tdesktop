/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#include "ui/empty_userpic.h"

#include "info/channel_statistics/earn/earn_icons.h"
#include "ui/chat/chat_style.h"
#include "ui/effects/animation_value.h"
#include "ui/emoji_config.h"
#include "ui/painter.h"
#include "ui/ui_utility.h"
#include "styles/style_chat.h"
#include "styles/style_dialogs.h"
#include "styles/style_widgets.h"
#include "styles/style_info.h"

#include <QtCore/QMutex>
#include <QtSvg/QSvgRenderer>

namespace Ui {

namespace {

// این بخش‌ها دیگر رسم نمی‌کنند، فقط return

[[nodiscard]] bool IsExternal(const QString &name) {
	return !name.isEmpty()
		&& (name.front() == QChar(0))
		&& QStringView(name).mid(1) == u"external"_q;
}

[[nodiscard]] bool IsInaccessible(const QString &name) {
	return !name.isEmpty()
		&& (name.front() == QChar(0))
		&& QStringView(name).mid(1) == u"inaccessible"_q;
}

void PaintSavedMessagesInner(QPainter&, int, int, int, const style::color&) { return; }
void PaintIconInner(QPainter&, int, int, int, int, const style::icon&, const style::color&) { return; }
void PaintRepliesMessagesInner(QPainter&, int, int, int, const style::color&) { return; }
void PaintHiddenAuthorInner(QPainter&, int, int, int, const style::color&) { return; }
void PaintMyNotesInner(QPainter&, int, int, int, const style::color&) { return; }
void PaintCurrencyInner(QPainter&, int, int, int, const style::color&) { return; }
void PaintExternalMessagesInner(QPainter&, int, int, int, const style::color&) { return; }
void PaintInaccessibleAccountInner(QPainter&, int, int, int, const style::color&) { return; }

[[nodiscard]] QImage Generate(int size, Fn<void(QPainter&)> callback) {
    Q_UNUSED(size)
    Q_UNUSED(callback)
	return QImage();
}

} // namespace

EmptyUserpic::EmptyUserpic(const BgColors &colors, const QString &name)
: _colors(colors) {
	fillString(name);
}

EmptyUserpic::~EmptyUserpic() = default;

QString EmptyUserpic::ExternalName() {
	return QChar(0) + u"external"_q;
}

QString EmptyUserpic::InaccessibleName() {
	return QChar(0) + u"inaccessible"_q;
}

uint8 EmptyUserpic::ColorIndex(uint64 id) {
	return 0;
}

EmptyUserpic::BgColors EmptyUserpic::UserpicColor(uint8 colorIndex) {
	return { nullptr, nullptr };
}

void EmptyUserpic::paint(
	QPainter &/*p*/,
	int /*x*/,
	int /*y*/,
	int /*outerWidth*/,
	int /*size*/,
	Fn<void()> /*paintBackground*/) const {
	return;
}

void EmptyUserpic::paintCircle(
	QPainter &/*p*/,
	int /*x*/,
	int /*y*/,
	int /*outerWidth*/,
	int /*size*/) const {
	return;
}

void EmptyUserpic::paintRounded(
	QPainter &/*p*/,
	int /*x*/,
	int /*y*/,
	int /*outerWidth*/,
	int /*size*/,
	int /*radius*/) const {
	return;
}

void EmptyUserpic::paintSquare(
	QPainter &/*p*/,
	int /*x*/,
	int /*y*/,
	int /*outerWidth*/,
	int /*size*/) const {
	return;
}

void EmptyUserpic::paintMonoforum(
	QPainter &/*p*/,
	int /*x*/,
	int /*y*/,
	int /*outerWidth*/,
	int /*size*/) const {
	return;
}

void EmptyUserpic::PaintSavedMessages(QPainter&, int, int, int, int) { return; }
void EmptyUserpic::PaintSavedMessages(QPainter&, int, int, int, int, QBrush, const style::color&) { return; }
QImage EmptyUserpic::GenerateSavedMessages(int) { return QImage(); }
void EmptyUserpic::PaintRepliesMessages(QPainter&, int, int, int, int) { return; }
void EmptyUserpic::PaintRepliesMessages(QPainter&, int, int, int, int, QBrush, const style::color&) { return; }
QImage EmptyUserpic::GenerateRepliesMessages(int) { return QImage(); }
void EmptyUserpic::PaintHiddenAuthor(QPainter&, int, int, int, int) { return; }
void EmptyUserpic::PaintHiddenAuthor(QPainter&, int, int, int, int, QBrush, const style::color&) { return; }
QImage EmptyUserpic::GenerateHiddenAuthor(int) { return QImage(); }
void EmptyUserpic::PaintMyNotes(QPainter&, int, int, int, int) { return; }
void EmptyUserpic::PaintMyNotes(QPainter&, int, int, int, int, QBrush, const style::color&) { return; }
QImage EmptyUserpic::GenerateMyNotes(int) { return QImage(); }
void EmptyUserpic::PaintCurrency(QPainter&, int, int, int, int) { return; }
void EmptyUserpic::PaintCurrency(QPainter&, int, int, int, int, QBrush, const style::color&) { return; }
QImage EmptyUserpic::GenerateCurrency(int) { return QImage(); }

std::pair<uint64, uint64> EmptyUserpic::uniqueKey() const {
	return { 0, 0 };
}

QPixmap EmptyUserpic::generate(int) {
	return QPixmap();
}

void EmptyUserpic::fillString(const QString &) {
	_string.clear();
}

QImage MonoforumShapeMask(QSize) {
	return QImage();
}

const QImage &MonoforumShapeMaskCached(QSize) {
	static auto mask = QImage();
	return mask;
}

QImage ApplyMonoforumShape(QImage image) {
	return image;
}

void PaintMonoforumShape(QPainter&, QRect) {
	return;
}

} // namespace Ui
