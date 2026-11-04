
bool __fastcall FUN_0047a1e0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  uVar5 = 0;
  iVar2 = FUN_004cfb40(*param_1);
  uVar3 = FUN_0043b320(*(undefined4 *)(iVar2 + 0x24),uVar5,uVar6);
  iVar2 = FUN_004cfb40(*param_1);
  uVar1 = *(uint *)(iVar2 + 0x28);
  iVar2 = FUN_004cfb40(*param_1);
  switch((int)((int)*(char *)(iVar2 + 0x20) & 0xf0U) >> 4) {
  case 0:
    bVar4 = (int)uVar1 < (int)uVar3;
    break;
  case 1:
    bVar4 = (int)uVar1 <= (int)uVar3;
    break;
  case 2:
    bVar4 = uVar3 == uVar1;
    break;
  case 3:
    bVar4 = (int)uVar3 <= (int)uVar1;
    break;
  case 4:
    bVar4 = (int)uVar3 < (int)uVar1;
    break;
  case 5:
    bVar4 = uVar3 != uVar1;
    break;
  case 6:
    bVar4 = (uVar3 & uVar1) == uVar1;
    break;
  default:
    bVar4 = false;
  }
  return bVar4;
}

