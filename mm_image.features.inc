<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function mm_image_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function mm_image_imagecache_default_presets() {
  $items = array(
    'image_gallery_thumbnail_medium' => array(
      'presetname' => 'image_gallery_thumbnail_medium',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '100',
            'height' => '100',
          ),
        ),
      ),
    ),
    'image_gallery_thumbnail_small' => array(
      'presetname' => 'image_gallery_thumbnail_small',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '50',
            'height' => '50',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function mm_image_node_info() {
  $items = array(
    'image' => array(
      'name' => t('Image'),
      'module' => 'features',
      'description' => t('An image.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'image_gallery' => array(
      'name' => t('Image Gallery'),
      'module' => 'features',
      'description' => t('A series of images presented as a gallery.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
