from abc import ABC, abstractmethod
from ex0.creatures import Creature


class HealCapability(ABC):
    def __init__(self, name: str) -> None:
        self.name = name

    @abstractmethod
    def heal(self, target: Creature | None = None) -> str:
        pass


class TransformCapability(ABC):
    def __init__(self, name: str, transformed: bool) -> None:
        self.name = name
        self.transformed = transformed

    @abstractmethod
    def transform(self) -> str:
        pass

    @abstractmethod
    def revert(self) -> str:
        pass
