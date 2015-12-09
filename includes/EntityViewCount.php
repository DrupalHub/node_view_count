<?php

/**
 * Class EntityViewCount.
 *
 * Representing views of entities.
 */
class EntityViewCount extends Entity {

  /**
   * @var integer
   *
   * The identifier of the entity.
   */
  public $id;

  /**
   * @var string
   *
   * The type of the entity bundle.
   */
  public $type;

  /**
   * @var string
   *
   * The entity type the entry relate to.
   */
  public $entity_type;

  /**
   * @var integer
   *
   * The entity id the entry relate to.
   */
  public $entity_id;

  /**
   * @var string
   *
   * The entity owner UID.
   */
  public $entity_owner;

  /**
   * @var string
   *
   * The view mode when the entity was viewed.
   */
  public $view_mode;

  /**
   * @var integer
   *
   * The unix time stamp the entry created.
   */
  public $created;

  /**
   * @var integer
   *
   * The user ID that the view the entity which the entry relate to.
   */
  public $uid;

}
