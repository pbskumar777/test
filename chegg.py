class Monster:
    def __init__(self, name, attack_type = "Normal", max_hp = 20):
      self.name = name
      self.attack_type = attack_type
      self.max_hp = max_hp
      self.current_hp = max_hp
      self.exp = 0
      self.attacks = { "wait" : 0 }
      self.possible_attacks = {
          "sneak_attack" : 1,
          "slash" : 2,
          "ice_storm" : 3,
          "fire_storm" : 3,
          "whirlwind" : 3,
          "earthquake" : 2,
          "double_hit" : 4,
          "tornado" : 4,
          "wait" : 0
      }

    def add_attack(self,attack_name):
        if(len(self.attacks)<4 and attack_name in self.possible_attacks.keys()):
            self.attacks[attack_name] = self.possible_attacks[attack_name]
            return True
        else:
            popup_list = []
            min_score = min(self.attacks.values())
            for i in self.attacks:
                if(self.attacks[i]==min_score):
                    popup_list.append(i)
            popup_list.sort()
            del self.attacks[popup_list[0]]
            if(attack_name in self.possible_attacks.keys()):
                self.attacks[attack_name] = self.possible_attacks[attack_name]
                return True
        return False

    
    def remove_attack(self,attack_name):
        if(attack_name in self.possible_attacks.keys()):
            if(len(self.attack)==1):
                del self.attacks[attack_name]
                self.attacks['wait'] = 0
            else:
                del self.attacks[attack_name]
            return True
        else:
            return False

    def winfight(self):
        self.exp += 5
        self.current_hp = self.max_hp

    def losefight(self):
        self.exp += 1
        self.current_hp = self.max_hp

def monster_fight(monster1, monster2):
    turn = "mn1"
    if(turn=="mn1"):
        sorted(monster1.attacks.items(), key=lambda x: x[1])
        




if __name__ == '__main__':
    