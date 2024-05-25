
class RaiseError(Exception):
    def __init__(self, message: str) -> None:
        self.message = message
    def __str__(self) -> str:
        return 'Error: Message {} !'.format(self.message)
