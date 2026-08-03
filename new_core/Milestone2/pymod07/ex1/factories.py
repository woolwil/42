from ex0.creatures import Creature
from ex0.factories import CreatureFactory
from . import creatures


class HealingCreatureFactory(CreatureFactory):
    def create_base(self) -> Creature:
        return creatures.Sproutling()

    def create_evolved(self) -> Creature:
        return creatures.Bloomelle()


class TransformCreatureFactory(CreatureFactory):
    def create_base(self) -> Creature:
        return creatures.Shiftling()

    def create_evolved(self) -> Creature:
        return creatures.Morphagon()
