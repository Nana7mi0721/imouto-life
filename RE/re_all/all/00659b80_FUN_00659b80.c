
int FUN_00659b80(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint local_4;
  
  puVar6 = param_2;
  switch(*(undefined2 *)((int)param_2 + 2)) {
  case 4:
  case 0xd:
  case 0x10:
  case 0x12:
    break;
  default:
    return 2;
  }
  iVar3 = FUN_00655060(param_1,param_2,&local_4,8,&param_2);
  if ((iVar3 != 0) || (param_2 == (undefined4 *)0x0)) {
    *param_3 = 0;
    return iVar3;
  }
  sVar1 = *(short *)((int)puVar6 + 2);
  if ((sVar1 == 0x10) || (sVar1 == 0x12)) {
    *param_3 = param_2;
    if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
      FUN_0065a700(param_2,local_4);
    }
    return 0;
  }
  puVar4 = (undefined4 *)FUN_006507d0(local_4 * 8);
  if (puVar4 == (undefined4 *)0x0) {
    FUN_006507e0(param_2);
    return 7;
  }
  sVar1 = *(short *)((int)puVar6 + 2);
  if (((sVar1 == 4) || (sVar1 == 0xd)) &&
     (uVar5 = 0, puVar6 = puVar4, puVar7 = param_2, local_4 != 0)) {
    do {
      if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
        FUN_0065a600(puVar7);
      }
      uVar2 = *puVar7;
      puVar7 = puVar7 + 1;
      *puVar6 = uVar2;
      puVar6[1] = 0;
      puVar6 = puVar6 + 2;
      uVar5 = uVar5 + 1;
    } while (uVar5 < local_4);
  }
  FUN_006507e0(param_2);
  *param_3 = puVar4;
  return 0;
}

