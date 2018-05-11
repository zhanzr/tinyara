/****************************************************************************
 *
 * Copyright 2018 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/

#include <memory>
#include <media/MediaPlayer.h>
#include <media/FileInputDataSource.h>
#include "tc_common.h"

static const char *dummyfilepath = "/mnt/fileinputdatasource.raw";

static void SetUp(void)
{
	FILE *fp = fopen(dummyfilepath, "w");
	fputs("dummydata", fp);
	fclose(fp);
}

static void TearDown()
{
	remove(dummyfilepath);
}

static void utc_media_MediaPlayer_create_p(void)
{
	media::MediaPlayer mp;
	TC_ASSERT_EQ("utc_media_MediaPlayer_create", mp.create(), media::PLAYER_OK);

	mp.destroy();
	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_create_n(void)
{
	media::MediaPlayer mp;
	mp.create();

	TC_ASSERT_EQ("utc_media_MediaPlayer_create", mp.create(), media::PLAYER_ERROR);

	mp.destroy();
	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_destroy_p(void)
{
	media::MediaPlayer mp;
	mp.create();

	TC_ASSERT_EQ("utc_media_MediaPlayer_destroy", mp.destroy(), media::PLAYER_OK);

	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_destroy_n(void)
{
	media::MediaPlayer mp;

	TC_ASSERT_EQ("utc_media_MediaPlayer_destroy", mp.destroy(), media::PLAYER_ERROR);

	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_setDataSource_p(void)
{
	media::MediaPlayer mp;
	std::unique_ptr<media::stream::FileInputDataSource> source = std::move(std::unique_ptr<media::stream::FileInputDataSource>(new media::stream::FileInputDataSource(dummyfilepath)));
	source->setSampleRate(20000);
	source->setChannels(2);
	mp.create();

	TC_ASSERT_EQ("utc_media_MediaPlayer_setDataSource", mp.setDataSource(std::move(source)), media::PLAYER_OK);

	mp.destroy();
	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_setDataSource_n(void)
{
	media::MediaPlayer mp;
	mp.create();

	TC_ASSERT_EQ("utc_media_MediaPlayer_setDataSource", mp.setDataSource(nullptr), media::PLAYER_ERROR);

	mp.destroy();
	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_setObserver_p(void)
{
	media::MediaPlayer mp;
	mp.create();

	TC_ASSERT_EQ("utc_media_MediaPlayer_setObserver", mp.setObserver(nullptr), media::PLAYER_OK);

	mp.destroy();
	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_setObserver_n(void)
{
	media::MediaPlayer mp;

	TC_ASSERT_EQ("utc_media_MediaPlayer_setObserver", mp.setObserver(nullptr), media::PLAYER_ERROR);

	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_prepare_p(void)
{
	media::MediaPlayer mp;
	std::unique_ptr<media::stream::FileInputDataSource> source = std::move(std::unique_ptr<media::stream::FileInputDataSource>(new media::stream::FileInputDataSource(dummyfilepath)));
	mp.create();
	mp.setDataSource(std::move(source));

	TC_ASSERT_EQ("utc_media_MediaPlayer_prepare", mp.prepare(), media::PLAYER_OK);

	mp.unprepare();
	mp.destroy();
	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_prepare_n(void)
{
	media::MediaPlayer mp;

	TC_ASSERT_EQ("utc_media_MediaPlayer_prepare", mp.prepare(), media::PLAYER_ERROR);

	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_unprepare_p(void)
{
	media::MediaPlayer mp;
	std::unique_ptr<media::stream::FileInputDataSource> source = std::move(std::unique_ptr<media::stream::FileInputDataSource>(new media::stream::FileInputDataSource(dummyfilepath)));
	mp.create();
	mp.setDataSource(std::move(source));
	mp.prepare();

	TC_ASSERT_EQ("utc_media_MediaPlayer_unprepare", mp.unprepare(), media::PLAYER_OK);

	mp.destroy();
	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_unprepare_n(void)
{
	media::MediaPlayer mp;

	TC_ASSERT_EQ("utc_media_MediaPlayer_unprepare", mp.unprepare(), media::PLAYER_ERROR);

	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_start_p(void)
{
	media::MediaPlayer mp;
	std::unique_ptr<media::stream::FileInputDataSource> source = std::move(std::unique_ptr<media::stream::FileInputDataSource>(new media::stream::FileInputDataSource(dummyfilepath)));
	mp.create();
	mp.setDataSource(std::move(source));
	mp.prepare();

	TC_ASSERT_EQ("utc_media_MediaPlayer_start", mp.start(), media::PLAYER_OK);

	mp.unprepare();
	mp.destroy();
	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_start_n(void)
{
	media::MediaPlayer mp;

	TC_ASSERT_EQ("utc_media_MediaPlayer_start", mp.start(), media::PLAYER_ERROR);

	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_pause_p(void)
{
	media::MediaPlayer mp;
	std::unique_ptr<media::stream::FileInputDataSource> source = std::move(std::unique_ptr<media::stream::FileInputDataSource>(new media::stream::FileInputDataSource(dummyfilepath)));
	mp.create();
	mp.setDataSource(std::move(source));
	mp.prepare();
	mp.start();

	TC_ASSERT_EQ("utc_media_MediaPlayer_pause", mp.pause(), media::PLAYER_OK);

	mp.unprepare();
	mp.destroy();
	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_pause_n(void)
{
	media::MediaPlayer mp;

	TC_ASSERT_EQ("utc_media_MediaPlayer_pause", mp.pause(), media::PLAYER_ERROR);

	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_stop_p(void)
{
	media::MediaPlayer mp;
	std::unique_ptr<media::stream::FileInputDataSource> source = std::move(std::unique_ptr<media::stream::FileInputDataSource>(new media::stream::FileInputDataSource(dummyfilepath)));
	mp.create();
	mp.setDataSource(std::move(source));
	mp.prepare();
	mp.start();

	TC_ASSERT_EQ("utc_media_MediaPlayer_stop", mp.stop(), media::PLAYER_OK);

	mp.unprepare();
	mp.destroy();
	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_stop_n(void)
{
	media::MediaPlayer mp;

	TC_ASSERT_EQ("utc_media_MediaPlayer_stop", mp.stop(), media::PLAYER_ERROR);

	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_getVolume_p(void)
{
	media::MediaPlayer mp;
	std::unique_ptr<media::stream::FileInputDataSource> source = std::move(std::unique_ptr<media::stream::FileInputDataSource>(new media::stream::FileInputDataSource(dummyfilepath)));
	mp.create();
	mp.setDataSource(std::move(source));
	mp.prepare();

	TC_ASSERT_GEQ("utc_media_MediaPlayer_getVolume", mp.getVolume(), 0);

	mp.unprepare();
	mp.destroy();
	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_getVolume_n(void)
{
	media::MediaPlayer mp;

	TC_ASSERT_LT("utc_media_MediaPlayer_getVolume", mp.getVolume(), 0);

	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_setVolume_p(void)
{
	media::MediaPlayer mp;
	std::unique_ptr<media::stream::FileInputDataSource> source = std::move(std::unique_ptr<media::stream::FileInputDataSource>(new media::stream::FileInputDataSource(dummyfilepath)));
	mp.create();
	mp.setDataSource(std::move(source));
	mp.prepare();

	auto ret =  mp.setVolume(0);
	TC_ASSERT_EQ("utc_media_MediaPlayer_setVolume", ret, media::PLAYER_OK);
	TC_ASSERT_EQ("utc_media_MediaPlayer_setVolume", mp.getVolume(), 0);

	mp.unprepare();
	mp.destroy();
	TC_SUCCESS_RESULT();
}

static void utc_media_MediaPlayer_setVolume_n(void)
{
	media::MediaPlayer mp;

	TC_ASSERT_EQ("utc_media_MediaPlayer_setVolume", mp.setVolume(0), media::PLAYER_ERROR);

	TC_SUCCESS_RESULT();
}

int utc_media_MediaPlayer_main(void)
{
	SetUp();
	utc_media_MediaPlayer_create_p();
	utc_media_MediaPlayer_create_n();
	utc_media_MediaPlayer_destroy_p();
	utc_media_MediaPlayer_destroy_n();
	utc_media_MediaPlayer_setDataSource_p();
	utc_media_MediaPlayer_setDataSource_n();
	utc_media_MediaPlayer_setObserver_p();
	utc_media_MediaPlayer_setObserver_n();
	utc_media_MediaPlayer_prepare_p();
	utc_media_MediaPlayer_prepare_n();
	utc_media_MediaPlayer_unprepare_p();
	utc_media_MediaPlayer_unprepare_n();
	utc_media_MediaPlayer_start_p();
	utc_media_MediaPlayer_start_n();
	utc_media_MediaPlayer_pause_p();
	utc_media_MediaPlayer_pause_n();
	utc_media_MediaPlayer_stop_p();
	utc_media_MediaPlayer_stop_n();
	utc_media_MediaPlayer_getVolume_p();
	utc_media_MediaPlayer_getVolume_n();
	utc_media_MediaPlayer_setVolume_p();
	utc_media_MediaPlayer_setVolume_n();
	TearDown();
	return 0;
}