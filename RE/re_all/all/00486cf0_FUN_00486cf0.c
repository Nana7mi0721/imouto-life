
bool __fastcall FUN_00486cf0(int param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar2 = FUN_0043b320(*(undefined4 *)(param_1 + 0x24),0,0);
  uVar1 = *(uint *)(param_1 + 0x28);
  switch((int)((int)*(char *)(param_1 + 0x20) & 0xf0U) >> 4) {
  case 0:
    bVar3 = (int)uVar1 < (int)uVar2;
    break;
  case 1:
    bVar3 = (int)uVar1 <= (int)uVar2;
    break;
  case 2:
    bVar3 = uVar2 == uVar1;
    break;
  case 3:
    bVar3 = (int)uVar2 <= (int)uVar1;
    break;
  case 4:
    bVar3 = (int)uVar2 < (int)uVar1;
    break;
  case 5:
    bVar3 = uVar2 != uVar1;
    break;
  case 6:
    bVar3 = (uVar2 & uVar1) == uVar1;
    break;
  default:
    bVar3 = false;
  }
  return bVar3;
}

