/**
 * @file    ulog_camera_information.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_camera_information.h"
#include "ulog_def.h"

const char ulog_camera_information_format[] = "camera_information:uint64_t timestamp;uint32_t time_boot_ms;uint8_t[32] vendor_name;uint8_t[32] model_name;uint32_t firmware_version;float focal_length;float sensor_size_h;float sensor_size_v;uint16_t resolution_h;uint16_t resolution_v;uint8_t lens_id;uint32_t flags;uint16_t cam_definition_version;char[140] cam_definition_uri;uint8_t gimbal_device_id;uint8_t camera_device_id;";
const char ulog_camera_information_name[] = "camera_information";

int32_t ulog_format_camera_information(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_camera_information_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_camera_information_format, sizeof(ulog_camera_information_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_camera_information(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_camera_information_name) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_SUBSCRIPTION,
    };

    if(log->state == ULOG_STATE_DEFINITIONS_CREATED)
        log->state = ULOG_STATE_WRITING_DATA;

    if(log->state != ULOG_STATE_WRITING_DATA)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &multi_id, sizeof(multi_id)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &log->msg_cnt, sizeof(log->msg_cnt)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_camera_information_name, sizeof(ulog_camera_information_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_camera_information(ulog_t *log, ulog_msg_id_t id, const ulog_camera_information_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)*32
                    + sizeof(uint8_t)*32
                    + sizeof(uint32_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint32_t)
                    + sizeof(uint16_t)
                    + sizeof(char)*140
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    ,
        .msg_type = ULOG_DEF_MSG_TYPE_LOGGED_DATA,
    };

    if(log->state != ULOG_STATE_WRITING_DATA || id >= log->msg_cnt) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &id, sizeof(id)) < 0) {
        return 1;
    }

    /* Timestamp [us] */
    if (lfs_file_write(log->lfs, log->file, &src->timestamp, sizeof(src->timestamp)) < 0) {
        return 1;
    }

    /* Timestamp (time since system boot). [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->time_boot_ms, sizeof(src->time_boot_ms)) < 0) {
        return 1;
    }

    /* Name of the camera vendor */
    if (lfs_file_write(log->lfs, log->file, src->vendor_name, sizeof(src->vendor_name)) < 0) {
        return 1;
    }

    /* Name of the camera model */
    if (lfs_file_write(log->lfs, log->file, src->model_name, sizeof(src->model_name)) < 0) {
        return 1;
    }

    /* Version of the camera firmware, encoded as: (Dev & 0xff) << 24 | (Patch & 0xff) << 16 | (Minor & 0xff) << 8 | (Major & 0xff). Use 0 if not known. */
    if (lfs_file_write(log->lfs, log->file, &src->firmware_version, sizeof(src->firmware_version)) < 0) {
        return 1;
    }

    /* Focal length. Use NaN if not known. [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->focal_length, sizeof(src->focal_length)) < 0) {
        return 1;
    }

    /* Image sensor size horizontal. Use NaN if not known. [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->sensor_size_h, sizeof(src->sensor_size_h)) < 0) {
        return 1;
    }

    /* Image sensor size vertical. Use NaN if not known. [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->sensor_size_v, sizeof(src->sensor_size_v)) < 0) {
        return 1;
    }

    /* Horizontal image resolution. Use 0 if not known. [pix] */
    if (lfs_file_write(log->lfs, log->file, &src->resolution_h, sizeof(src->resolution_h)) < 0) {
        return 1;
    }

    /* Vertical image resolution. Use 0 if not known. [pix] */
    if (lfs_file_write(log->lfs, log->file, &src->resolution_v, sizeof(src->resolution_v)) < 0) {
        return 1;
    }

    /* Reserved for a lens ID.  Use 0 if not known. */
    if (lfs_file_write(log->lfs, log->file, &src->lens_id, sizeof(src->lens_id)) < 0) {
        return 1;
    }

    /* Bitmap of camera capability flags. */
    if (lfs_file_write(log->lfs, log->file, &src->flags, sizeof(src->flags)) < 0) {
        return 1;
    }

    /* Camera definition version (iteration).  Use 0 if not known. */
    if (lfs_file_write(log->lfs, log->file, &src->cam_definition_version, sizeof(src->cam_definition_version)) < 0) {
        return 1;
    }

    /* Camera definition URI (if any, otherwise only basic functions will be available). HTTP- (http://) and MAVLink FTP- (mavlinkftp://) formatted URIs are allowed (and both must be supported by any GCS that implements the Camera Protocol). The definition file may be xz compressed, which will be indicated by the file extension .xml.xz (a GCS that implements the protocol must support decompressing the file). The string needs to be zero terminated.  Use a zero-length string if not known. */
    if (lfs_file_write(log->lfs, log->file, src->cam_definition_uri, sizeof(src->cam_definition_uri)) < 0) {
        return 1;
    }

    /* Gimbal id of a gimbal associated with this camera. This is the component id of the gimbal device, or 1-6 for non mavlink gimbals. Use 0 if no gimbal is associated with the camera. */
    if (lfs_file_write(log->lfs, log->file, &src->gimbal_device_id, sizeof(src->gimbal_device_id)) < 0) {
        return 1;
    }

    /* Camera id of a non-MAVLink camera attached to an autopilot (1-6).  0 if the component is a MAVLink camera (with its own component id). */
    if (lfs_file_write(log->lfs, log->file, &src->camera_device_id, sizeof(src->camera_device_id)) < 0) {
        return 1;
    }

    
    return 0;
}
