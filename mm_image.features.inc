<?php
/**
 * @file
 * mm_image.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mm_image_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function mm_image_image_default_styles() {
  $styles = array();

  // Exported image style: mm_image_square_thumb
  $styles['mm_image_square_thumb'] = array(
    'name' => 'mm_image_square_thumb',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '90',
          'height' => '90',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function mm_image_node_info() {
  $items = array(
    'image' => array(
      'name' => t('Image'),
      'base' => 'node_content',
      'description' => t('An image.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'image_gallery' => array(
      'name' => t('Image Gallery'),
      'base' => 'node_content',
      'description' => t('A series of images presented in a lightbox.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
