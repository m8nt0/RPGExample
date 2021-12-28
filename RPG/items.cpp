#include "items.h"
#include "sprites.h"

#include <vector>

std::vector<Item> ItemDB;

// ItemDatabase
Item* AddItem(const char* name, int sprite, ItemTypes type)
{
	int id = int(ItemDB.size());

	CenterSprite(sprite);
	ItemDB.emplace_back(Item{ id, std::string(name), sprite, type });
	return GetItem(id);
}

Item* GetItem(int id)
{
	if (id < 0 || id >= ItemDB.size())
	return nullptr;

	return &ItemDB[id];
}

int GetRandomItem(int except)
{
	int id = -1;
	while (id == -1)
	{
		int index = GetRandomValue(0, int(ItemDB.size()) - 1);
		id = ItemDB[index].Id;
		if (id == except)
			id = -1;
	}

	return id;
}

void SetupDefaultItems()
{
	// basic items
	auto* item = AddItem("Sword", SwordSprite, ItemTypes::Weapon);
	item->Attack.MinDamage = 0;
	item->Attack.MaxDamage = 2;
	item->Attack.Cooldown = 1;

	item = AddItem("Pleather Armor", LeatherArmorSprite, ItemTypes::Armor);
	item->Defense.Defense = 2;

	item = AddItem("Bag-o-Gold", BagSprite, ItemTypes::None);

	item = AddItem("Fud", FoodSprite, ItemTypes::Activatable);
	item->Effect = ActivatableEffects::Healing;
	item->Value = 5;

	// extended weapons
	item = AddItem("Cool Sword", CoolSwordSprite, ItemTypes::Weapon);
	item->Attack.MinDamage = 2;
	item->Attack.MaxDamage = 6;
	item->Attack.Cooldown = 1;

	item = AddItem("Awesome Sword", AwesomeSwordSprite, ItemTypes::Weapon);
	item->Attack.MinDamage = 4;
	item->Attack.MaxDamage = 8;
	item->Attack.Cooldown = 0.75f;

	item = AddItem("Axe", AxeSprite, ItemTypes::Weapon);
	item->Attack.MinDamage = 1;
	item->Attack.MaxDamage = 4;
	item->Attack.Cooldown = 1.5f;

	item = AddItem("Mighty Axe", MightyAxeSprite, ItemTypes::Weapon);
	item->Attack.MinDamage = 2;
	item->Attack.MaxDamage = 7;
	item->Attack.Cooldown = 1.5f;

	item = AddItem("Battle Fork Axe", ForkSprite, ItemTypes::Weapon);
	item->Attack.MinDamage = 1;
	item->Attack.MaxDamage = 3;
	item->Attack.Range = 20;
	item->Attack.Cooldown = 0.5f;

	item = AddItem("Bow", BowSprite, ItemTypes::Weapon);
	item->Attack.MinDamage = 1;
	item->Attack.MaxDamage = 3;
	item->Attack.Melee = false;
	item->Attack.Range = 150.0f;
	item->Attack.Cooldown = 0.25f;

	item = AddItem("Sweet Bow", GoodBowSprite, ItemTypes::Weapon);
	item->Attack.MinDamage = 3;
	item->Attack.MaxDamage = 6;
	item->Attack.Melee = false;
	item->Attack.Range = 250.0f;
	item->Attack.Cooldown = 0.25f;

	item = AddItem("Bonkmaster 5000", ClubSprite, ItemTypes::Weapon);
	item->Attack.MinDamage = 6;
	item->Attack.MaxDamage = 10;
	item->Attack.Range = 15.0f;
	item->Attack.Cooldown = 3;

	// extended armor
	item = AddItem("Chain Shirt", ChainArmorSprite, ItemTypes::Armor);
	item->Defense.Defense = 4;

	item = AddItem("Full Plate", PlateArmorSprite, ItemTypes::Armor);
	item->Defense.Defense = 10;

	// extended activatables
	item = AddItem("Potion", PotionSprite, ItemTypes::Activatable);
	item->Effect = ActivatableEffects::Healing;
	item->Value = 20;

	item = AddItem("Shield", ShieldSprite, ItemTypes::Activatable);
	item->Effect = ActivatableEffects::Defense;
	item->Value = 10;
	item->Durration = 30;

	item = AddItem("Fireball Scroll", FireballSprite, ItemTypes::Activatable);
	item->Effect = ActivatableEffects::Damage;
	item->Value = 20;
}