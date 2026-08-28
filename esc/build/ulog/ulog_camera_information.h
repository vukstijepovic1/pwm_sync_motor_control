/**
 * @file    ulog_camera_information.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_CAMERA_INFORMATION_H
#define ULOG_CAMERA_INFORMATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_camera_information_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    uint8_t vendor_name[32]; /* Name of the camera vendor */
    uint8_t model_name[32]; /* Name of the camera model */
    uint32_t firmware_version; /* Version of the camera firmware, encoded as: (Dev & 0xff) << 24 | (Patch & 0xff) << 16 | (Minor & 0xff) << 8 | (Major & 0xff). Use 0 if not known. */
    float focal_length; /* Focal length. Use NaN if not known. [mm] */
    float sensor_size_h; /* Image sensor size horizontal. Use NaN if not known. [mm] */
    float sensor_size_v; /* Image sensor size vertical. Use NaN if not known. [mm] */
    uint16_t resolution_h; /* Horizontal image resolution. Use 0 if not known. [pix] */
    uint16_t resolution_v; /* Vertical image resolution. Use 0 if not known. [pix] */
    uint8_t lens_id; /* Reserved for a lens ID.  Use 0 if not known. */
    uint32_t flags; /* Bitmap of camera capability flags. */
    uint16_t cam_definition_version; /* Camera definition version (iteration).  Use 0 if not known. */
    char cam_definition_uri[140]; /* Camera definition URI (if any, otherwise only basic functions will be available). HTTP- (http://) and MAVLink FTP- (mavlinkftp://) formatted URIs are allowed (and both must be supported by any GCS that implements the Camera Protocol). The definition file may be xz compressed, which will be indicated by the file extension .xml.xz (a GCS that implements the protocol must support decompressing the file). The string needs to be zero terminated.  Use a zero-length string if not known. */
    uint8_t gimbal_device_id; /* Gimbal id of a gimbal associated with this camera. This is the component id of the gimbal device, or 1-6 for non mavlink gimbals. Use 0 if no gimbal is associated with the camera. */
    uint8_t camera_device_id; /* Camera id of a non-MAVLink camera attached to an autopilot (1-6).  0 if the component is a MAVLink camera (with its own component id). */
    
} ulog_camera_information_t;

/**
 * Defines Camera Information message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_camera_information(ulog_t *log);

/**
 * Subscribe Camera Information message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_camera_information(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Camera Information message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_camera_information(ulog_t *log, ulog_msg_id_t id, const ulog_camera_information_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_CAMERA_INFORMATION_H */