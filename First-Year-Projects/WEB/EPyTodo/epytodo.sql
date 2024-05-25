CREATE DATABASE IF NOT EXISTS epytodo;
USE epytodo;

CREATE TABLE IF NOT EXISTS epytodo_user (
    `id` INT NOT NULL AUTO_INCREMENT
    `email` VARCHAR(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL
    `password` VARCHAR(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL
    `name` TEXT CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL
    `firstname` TEXT CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
    PRIMARY KEY (`id`)) ENGINE = MyISAM
);

CREATE TABLE IF NOT EXISTS epytodo_todo (
    `id` INT NOT NULL AUTO_INCREMENT
    `title` VARCHAR(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL
    `description` VARCHAR(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL
    `created_at` DATETIME(255) NOT NULL DEFAULT CURRENT_TIMESTAMP , `due_time` DATETIME(255) NOT NULL
    `status` ENUM('todo', 'in progress', 'done') DEFAULT "not started" CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL
    `user_id` INT UNSIGNED NOT NULL , PRIMARY KEY (`id`)) ENGINE = MyISAM
);