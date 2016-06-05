#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <sstream>
#include <array>
#include "../Dependencies/tinyxml/tinyxml.h"

typedef std::string String;
typedef std::stringstream StringStream;

static const auto NumClasses = 16;
static const auto NumEffects = 12;
static const auto NumComponents = 4;
static const auto NumFields = 215;
typedef std::array<String, NumFields> Spell;
typedef std::vector<Spell*> SpellFile;

namespace FieldIndex {
	enum FieldIndex : int {
		ID,
		Name,
		Player,
		TeleportZone,
		YouCast,
		OtherCasts,
		CastOnYou,
		CastOnOther,
		FadeMessage,
		Range,
		AOERange,
		PushBack,
		PushUp,
		CastTime,
		RecoveryTime,
		RecastTime,
		BuffDurationFormula,
		BuffDuration,
		AOEDuration,
		ManaCost,
		EffectBase1,
		EffectBase2,
		EffectBase3,
		EffectBase4,
		EffectBase5,
		EffectBase6,
		EffectBase7,
		EffectBase8,
		EffectBase9,
		EffectBase10,
		EffectBase11,
		EffectBase12,
		EffectLimit1,
		EffectLimit2,
		EffectLimit3,
		EffectLimit4,
		EffectLimit5,
		EffectLimit6,
		EffectLimit7,
		EffectLimit8,
		EffectLimit9,
		EffectLimit10,
		EffectLimit11,
		EffectLimit12,
		EffectMax1,
		EffectMax2,
		EffectMax3,
		EffectMax4,
		EffectMax5,
		EffectMax6,
		EffectMax7,
		EffectMax8,
		EffectMax9,
		EffectMax10,
		EffectMax11,
		EffectMax12,
		Icon,
		MemIcon,
		ComponentID_1,
		ComponentID_2,
		ComponentID_3,
		ComponentID_4,
		ComponentCount_1,
		ComponentCount_2,
		ComponentCount_3,
		ComponentCount_4,
		NoExpendReagent_1,
		NoExpendReagent_2,
		NoExpendReagent_3,
		NoExpendReagent_4,
		EffectFormula1,
		EffectFormula2,
		EffectFormula3,
		EffectFormula4,
		EffectFormula5,
		EffectFormula6,
		EffectFormula7,
		EffectFormula8,
		EffectFormula9,
		EffectFormula10,
		EffectFormula11,
		EffectFormula12,
		LightType,
		GoodEffect,
		Activated,
		ResistType,
		EffectID1,
		EffectID2,
		EffectID3,
		EffectID4,
		EffectID5,
		EffectID6,
		EffectID7,
		EffectID8,
		EffectID9,
		EffectID10,
		EffectID11,
		EffectID12,
		TargetType,
		BaseDifficulty,
		ZoneType,
		EnvironmentType,
		TimeOfDay,
		UNK,
		WAR_Level,
		CLR_Level,
		PAL_Level,
		RNG_Level,
		SHD_Level,
		DRU_Level,
		MNK_Level,
		BRD_Level,
		ROG_Level,
		SHM_Level,
		NEC_Level,
		WIZ_Level,
		MAG_Level,
		ENC_Level,
		BST_Level,
		BER_Level,
	};
}
std::vector<String> Classes = {
	"war",
	"clr",
	"pal",
	"rng",
	"shd",
	"dru",
	"mnk",
	"brd",
	"rog",
	"shm",
	"nec",
	"wiz",
	"mag",
	"enc",
	"bst",
	"ber",
};

std::vector<String> FieldNames = {
	"id",
	"name",
	"player",
	"teleport_zone",
	"you_cast",
	"other_casts",
	"cast_on_you",
	"cast_on_other",
	"fade_message",
	"range",
	"aoe_range",
	"push_back",
	"push_up",
	"cast_time",
	"recovery_time",
	"recast_time",
	"buff_duration_formula",
	"buff_duration",
	"aoe_duration",
	"mana",
	"effect_base_value_1",
	"effect_base_value_2",
	"effect_base_value_3",
	"effect_base_value_4",
	"effect_base_value_5",
	"effect_base_value_6",
	"effect_base_value_7",
	"effect_base_value_8",
	"effect_base_value_9",
	"effect_base_value_10",
	"effect_base_value_11",
	"effect_base_value_12",
	"effect_limit_value_1",
	"effect_limit_value_2",
	"effect_limit_value_3",
	"effect_limit_value_4",
	"effect_limit_value_5",
	"effect_limit_value_6",
	"effect_limit_value_7",
	"effect_limit_value_8",
	"effect_limit_value_9",
	"effect_limit_value_10",
	"effect_limit_value_11",
	"effect_limit_value_12",
	"max_1",
	"max_2",
	"max_3",
	"max_4",
	"max_5",
	"max_6",
	"max_7",
	"max_8",
	"max_9",
	"max_10",
	"max_11",
	"max_12",
	"icon",
	"memicon",
	"components_1",
	"components_2",
	"components_3",
	"components_4",
	"components_count_1",
	"components_count_2",
	"components_count_3",
	"components_count_4",
	"no_expend_reagent_1",
	"no_expend_reagent_2",
	"no_expend_reagent_3",
	"no_expend_reagent_4",
	"formula_1",
	"formula_2",
	"formula_3",
	"formula_4",
	"formula_5",
	"formula_6",
	"formula_7",
	"formula_8",
	"formula_9",
	"formula_10",
	"formula_11",
	"formula_12",
	"light_type",
	"good_effect",
	"activated",
	"resist_type",
	"effect_id_1",
	"effect_id_2",
	"effect_id_3",
	"effect_id_4",
	"effect_id_5",
	"effect_id_6",
	"effect_id_7",
	"effect_id_8",
	"effect_id_9",
	"effect_id_10",
	"effect_id_11",
	"effect_id_12",
	"target_type",
	"base_difficulty",
	"zone_type",
	"environment_type",
	"time_of_day",
	"warrior_level",
	"cleric_level",
	"paladin_level",
	"ranger_level",
	"shadowknight_level",
	"druid_level",
	"monk_level",
	"bard_level",
	"rogue_level",
	"shaman_level",
	"necromancer_level",
	"wizard_level",
	"magician_level",
	"enchanter_level",
	"beastlord_level",
	"berzerker_level",
	"casting_animation",
	"target_animation",
	"travel_type",
	"spell_affect_index",
	"unknown_0",
	"field_124",
	"field_125",
	"diety_1",
	"diety_2",
	"diety_3",
	"diety_4",
	"diety_5",
	"diety_6",
	"diety_7",
	"diety_8",
	"diety_9",
	"diety_10",
	"diety_11",
	"diety_12",
	"diety_13",
	"diety_14",
	"diety_15",
	"diety_16",
	"field_142",
	"field_143",
	"new_icon",
	"spell_animation",
	"uninterruptible",
	"resist_difference",
	"dot_stacking_exempt",
	"deleteable",
	"recourse_link",
	"no_partial_resist",
	"field_152",
	"field_153",
	"short_buff",
	"description_number",
	"type_description_number",
	"effect_description_number",
	"field_158",
	"npc_no_los",
	"field_160",
	"reflectable",
	"bonus_hate",
	"field_163",
	"field_164",
	"field_165",
	"endurance_cost",
	"endurance_timer_index",
	"is_discipline",
	"field_169",
	"field_170",
	"field_171",
	"field_172",
	"hate_added",
	"endurance_upkeep",
	"number_hits_type",
	"number_hits",
	"pvp_resist_base",
	"pvp_resist_calc",
	"pvp_resist_cap",
	"spell_category",
	"field_181",
	"field_182",
	"field_183",
	"field_184",
	"can_mgb",
	"no_dispell",
	"npc_category",
	"npc_usefulness",
	"min_resist",
	"max_resist",
	"field_191",
	"field_192",
	"nimbus_effect",
	"cone_start_angle",
	"cone_stop_angle",
	"field_196",
	"not_extendable",
	"field_198",
	"field_199",
	"suspendable",
	"viral_range",
	"song_cap",
	"field_203",
	"field_204",
	"field_205",
	"field_206",
	"spell_group",
	"rank",
	"field_209",
	"field_210",
	"cast_restriction",
	"allow_rest",
	"in_combat",
	"out_of_combat",
	"field_215",
	"field_216",
	"field_217",
	"aoe_max_targets",
	"max_targets",
	"field_220",
	"field_221",
	"field_222",
	"field_223",
	"persist_death",
	"field_225",
	"field_226",
	"min_distance",
	"min_distance_mod",
	"max_distance",
	"max_distance_mod",
	"min_range",
	"field_232",
	"field_233",
	"field_234",
	"field_235",
	"field_236"
};

// Thank you: http://stackoverflow.com/questions/236129/how-to-split-a-string-in-c
std::vector<String> &split(const String &s, char delim, std::vector<String> &elems) {
	StringStream ss(s);
	String item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

void spellLineSplit(const String& pString, Spell& pSpell) {
	StringStream ss(pString);
	for (auto i = 0; i < NumFields; i++) {
		std::getline(ss, pSpell[i], '^');
	}
}


// Thank you: http://stackoverflow.com/questions/236129/how-to-split-a-string-in-c
std::vector<String> split(const String &s, char delim) {
	std::vector<String> elems;
	split(s, delim, elems);
	return elems;
}

namespace Convert { 
	namespace XML {
		const bool _toTextImpl(TiXmlDocument* pInput, std::ofstream& pOutput) {
			if (!pInput) { return false; }

			auto spellsElement = pInput->FirstChildElement("spells");
			if (!spellsElement) { return false; }

			// Iterate <spell>
			auto spellElement = spellsElement->FirstChildElement("spell");
			while (spellElement) {
				// Iterate <spell> attributes.
				auto attribute = spellElement->FirstAttribute();
				while (attribute) {
					pOutput << attribute->Value();
					attribute = attribute->Next();
					if (attribute)
						pOutput << "^";
				}
				spellElement = spellElement->NextSiblingElement("spell");
				pOutput << std::endl;
			}

			return true;
		}
		const bool toText(const String& pInputFileName, const String& pOutputFileName) {
			
			// Create input
			TiXmlDocument* input = new TiXmlDocument(pInputFileName.c_str());
			if (!input->LoadFile()) {
				delete input;
				return false;
			}

			// Create output
			std::ofstream output;
			output.open(pOutputFileName.c_str(), std::ios::out);
			if (!output.is_open()) {
				delete input;
				return false;
			}

			const bool success = _toTextImpl(input, output);

			output.close();
			delete input;

			return success;
		}
	}
	namespace Text {
		const bool _toXMLImpl(std::ifstream& pInput, TiXmlDocument* pOutput) {
			if (!pInput) return false;

			auto spellsElement = static_cast<TiXmlElement*>(pOutput->LinkEndChild(new TiXmlElement("spells")));

			String line;
			auto c = 0;
			while (std::getline(pInput, line)) {
				if (c >= 100) break;
				c++;

				Spell s;
				spellLineSplit(line, s);

				auto spellElement = static_cast<TiXmlElement*>(spellsElement->LinkEndChild(new TiXmlElement("spell")));
				spellElement->SetAttribute("id", s[FieldIndex::ID].c_str());
				spellElement->SetAttribute("name", s[FieldIndex::Name].c_str());
				spellElement->SetAttribute("mana", s[FieldIndex::ManaCost].c_str());
				spellElement->SetAttribute("target", s[FieldIndex::TargetType].c_str());
				spellElement->SetAttribute("range", s[FieldIndex::Range].c_str());
				
				if (s[FieldIndex::ResistType] != "0")
					spellElement->SetAttribute("resist", s[FieldIndex::ResistType].c_str());

				//spellElement->SetAttribute("zone", s[FieldIndex::ZoneType].c_str());
				//spellElement->SetAttribute("env", s[FieldIndex::EnvironmentType].c_str());

				// Classes.
				auto classesElement = static_cast<TiXmlElement*>(spellElement->LinkEndChild(new TiXmlElement("classes")));
				for (auto i = 0; i < NumClasses; i++) {
					if (s[FieldIndex::WAR_Level + i] == "255") continue;
					classesElement->SetAttribute(Classes[i].c_str(), s[FieldIndex::WAR_Level + i].c_str());
				}

				// Effects.
				auto effectsElement = static_cast<TiXmlElement*>(spellElement->LinkEndChild(new TiXmlElement("effects")));
				for (auto i = 0; i < NumEffects; i++) {
					if (s[FieldIndex::EffectID1 + i] == "254") continue;

					auto effectElement = static_cast<TiXmlElement*>(effectsElement->LinkEndChild(new TiXmlElement("effect")));

					// ID
					effectElement->SetAttribute("type", s[FieldIndex::EffectID1 + i].c_str());
					// Formula
					effectElement->SetAttribute("formula", s[FieldIndex::EffectFormula1 + i].c_str());
					// Base
					effectElement->SetAttribute("base", s[FieldIndex::EffectBase1 + i].c_str());
					// Limit
					effectElement->SetAttribute("limit", s[FieldIndex::EffectLimit1 + i].c_str());
					// Max
					effectElement->SetAttribute("max", s[FieldIndex::EffectMax1 + i].c_str());
				}
				// Strip element if the spell has no effects.
				if (effectsElement->NoChildren())
					spellElement->RemoveChild(effectsElement);

			}

			return true;
			//if (!pInput) { return false; }

			//auto spellsElement = static_cast<TiXmlElement*>(pOutput->LinkEndChild(new TiXmlElement("spells")));

			//static const std::list<std::pair<int, int>> ignore = {
			//	{ FieldIndex::EffectBase1, FieldIndex::EffectMax12 },
			//	{ FieldIndex::ComponentID_1, FieldIndex::ComponentCount_4 },
			//	{ FieldIndex::EffectFormula1, FieldIndex::EffectFormula12 },
			//	{ FieldIndex::EffectID1, FieldIndex::EffectID12 },
			//};
			//auto inIgnored = [=](const int pFieldID){
			//	for (auto i : ignore) {
			//		if (pFieldID >= i.first && pFieldID <= i.second)
			//			return true;
			//	}
			//	return false;
			//};

			//// Iterate lines
			//String line;
			//auto count = 1;
			//while (std::getline(pInput, line)) {
			//	if (count >= 1000) break;
			//	std::cout << count << std::endl;
			//	auto spellElement = static_cast<TiXmlElement*>(spellsElement->LinkEndChild(new TiXmlElement("spell")));
			//	auto field = 0;
			//	std::vector<String> values = split(line, '^');
			//	for (auto i : values) {
			//		if (inIgnored(field)) { field++; continue; }
			//		if (i.empty()) { field++; continue; }

			//		spellElement->SetAttribute(FieldNames[field].c_str(), i.c_str());
			//		field++;
			//	}

			//	// Write effects.
			//	auto effectsElement = new TiXmlElement("effects");
			//	auto effectCount = 0;
			//	for (auto i = 0; i < 12; i++) {
			//		// Check for non 254 effect ID.
			//		if (values[FieldIndex::EffectID1 + i] == "254") continue;
			//		effectCount++;

			//		auto effectElement = static_cast<TiXmlElement*>(effectsElement->LinkEndChild(new TiXmlElement("effect")));
			//		// ID
			//		effectElement->SetAttribute("id", values[FieldIndex::EffectID1 + i].c_str());
			//		// Formula
			//		effectElement->SetAttribute("formula", values[FieldIndex::EffectFormula1 + i].c_str());
			//		// Base
			//		effectElement->SetAttribute("base", values[FieldIndex::EffectBase1 + i].c_str());
			//		// Limit
			//		effectElement->SetAttribute("limit", values[FieldIndex::EffectLimit1 + i].c_str());
			//		// Max
			//		effectElement->SetAttribute("max", values[FieldIndex::EffectMax1 + i].c_str());
			//	}
			//	if (effectCount)
			//		spellElement->LinkEndChild(effectsElement);
			//	else
			//		delete effectsElement;

			//	// Write Components.
			//	auto componentsElement = new TiXmlElement("components");
			//	auto componentCount = 0;
			//	for (auto i = 0; i < 4; i++) {
			//		// Check for non -1 component item ID.
			//		if (values[FieldIndex::ComponentID_1 + i] == "-1") continue;
			//		componentCount++;

			//		auto componentElement = static_cast<TiXmlElement*>(componentsElement->LinkEndChild(new TiXmlElement("component")));
			//		// Item ID.
			//		componentElement->SetAttribute("id", values[FieldIndex::ComponentID_1 + i].c_str());
			//		// Item count.
			//		componentElement->SetAttribute("count", values[FieldIndex::ComponentCount_1 + i].c_str());
			//	}
			//	if (componentCount)
			//		spellElement->LinkEndChild(componentsElement);
			//	else
			//		delete componentsElement;

			//	line.clear();
			//	count++;
			//}

			return true;
		}
		const bool toXML(const String& pInputFileName, const String& pOutputFileName) {
			// Create input
			std::ifstream input;
			input.open(pInputFileName.c_str(), std::ios::in);
			if (!input.is_open()) {
				return false;
			}

			// Create output
			TiXmlDocument* output = new TiXmlDocument(pOutputFileName.c_str());

			const bool success = _toXMLImpl(input, output);
			bool saved = false;

			std::cout << "Saving...";
			if (success)
				saved = output->SaveFile();

			input.close();
			delete output;
			std::cout << "Done" << std::endl;

			return success && saved;
		}
	}
}

void main() {
	//Convert::XML::toText("spells.xml", "spells_us.txt");
	Convert::Text::toXML("spells_us.txt", "spells.xml");

	//std::cout << FieldNames[104] << std::endl;
}