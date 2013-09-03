<?php

/**
 * Implements hook_rules_action_info().
 *
 * Declares any meta-data about actions for Rules in a big, associative, nested
 * array. See also hook_rules_action_info in the rules.api.php file, and the
 * online documentation at http://drupal.org/node/878928.
 */
function rules_i18n_rules_action_info() {
  $actions = array(
    'rules_i18n_action_add_to_translation_set' => array(
      'label' => t('Add to Content Translation Set'),
      'group' => t('Node'),
      // When declaring parameters, site builders will by default get a form to
      // select fitting data. In this case, we require the site builder to
      // select a user object. The 'type' could be any data type known to Rules,
      // which means any entity type known to Entity API or any additional data
      // type declared by hook_rules_data_info – by default including things
      // like 'integer', 'text' and more. See
      'parameter' => array(
        // Each parameter is keyed with an internally used machine name.
        'node' => array(
          'type' => 'node',
          'label' => t('Node to be modified'),
          // If we were to make changes to the parameter object, whe should set
          // the 'save' property to TRUE. This makes Rules handle the saving in
          // a more optimized way than if each action saved the objects.
          'save' => TRUE,
        ),
        'translation_node' => array(
          'type' => 'node',
          'label' => t('Node in another language to associate with'),
          // If we were to make changes to the parameter object, whe should set
          // the 'save' property to TRUE. This makes Rules handle the saving in
          // a more optimized way than if each action saved the objects.
          'save' => TRUE,
        ),
      ),
    ),
  );

  return $actions;
}

/**
 * The action function for the 'rules_i18n_action_add_to_translation_set'.
 *
 * The $node parameter is the node object sent into this action, selected in
 * the Rules configuration interface.
 * @param <object> $node
 *   The node object to work with. Selected by the site administrator when the
 *   action is configured.
 */
function rules_i18n_action_add_to_translation_set($node, $translation_node) {
  // if translation node does not have a translation set yet
  if ($translation_node->tnid == 0) {
    $translation_node->tnid = $translation_node->nid;
  }

  // Setting node translation node
  $node->tnid = $translation_node->nid;
}