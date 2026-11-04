
int FUN_00658580(int param_1,uint param_2,undefined4 *param_3)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  undefined2 uVar5;
  undefined2 extraout_var;
  ushort *puVar6;
  uint uVar7;
  ushort *local_8;
  ushort *local_4;
  
  uVar7 = param_2;
  switch(*(undefined2 *)(param_2 + 2)) {
  case 1:
  case 3:
  case 4:
  case 6:
  case 8:
  case 9:
  case 0x10:
  case 0x11:
    break;
  default:
    return 2;
  }
  iVar3 = FUN_00655060(param_1,param_2,&param_2,2,&local_8);
  if ((iVar3 != 0) || (local_8 == (ushort *)0x0)) {
    *param_3 = 0;
    return iVar3;
  }
  sVar1 = *(short *)(uVar7 + 2);
  if (sVar1 == 3) {
    uVar7 = 0;
    puVar4 = local_8;
    if (param_2 != 0) {
      do {
        uVar5 = (undefined2)(param_2 >> 0x10);
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a5f0(puVar4);
          uVar5 = extraout_var;
        }
        iVar3 = FUN_0065a0c0(CONCAT22(uVar5,*puVar4));
        if (iVar3 != 0) {
          FUN_006507e0(local_8);
          return iVar3;
        }
        puVar4 = puVar4 + 1;
        uVar7 = uVar7 + 1;
      } while (uVar7 < param_2);
    }
    *param_3 = local_8;
    return 0;
  }
  if (sVar1 == 8) {
    *param_3 = local_8;
    if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
      FUN_0065a660(local_8,param_2);
    }
    return 0;
  }
  puVar4 = (ushort *)FUN_006507d0(param_2 * 2);
  local_4 = puVar4;
  if (puVar4 == (ushort *)0x0) {
    FUN_006507e0(local_8);
    return 7;
  }
  iVar3 = 0;
  switch(*(undefined2 *)(uVar7 + 2)) {
  case 1:
    uVar7 = 0;
    puVar6 = local_8;
    if (param_2 != 0) {
      do {
        *puVar4 = (ushort)(byte)*puVar6;
        puVar4 = puVar4 + 1;
        puVar6 = (ushort *)((int)puVar6 + 1);
        uVar7 = uVar7 + 1;
      } while (uVar7 < param_2);
    }
    break;
  case 4:
    uVar7 = 0;
    puVar6 = local_8;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a600(puVar6);
        }
        iVar3 = FUN_0065a0d0(*(undefined4 *)puVar6);
        if (iVar3 != 0) break;
        uVar2 = *puVar6;
        puVar6 = puVar6 + 2;
        *puVar4 = uVar2;
        puVar4 = puVar4 + 1;
        uVar7 = uVar7 + 1;
      } while (uVar7 < param_2);
    }
    break;
  case 6:
    uVar7 = 0;
    puVar6 = local_8;
    if (param_2 != 0) {
      do {
        *puVar4 = (short)(char)(byte)*puVar6;
        puVar4 = puVar4 + 1;
        puVar6 = (ushort *)((int)puVar6 + 1);
        uVar7 = uVar7 + 1;
      } while (uVar7 < param_2);
    }
    break;
  case 9:
    uVar7 = 0;
    puVar6 = local_8;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a600(puVar6);
        }
        iVar3 = FUN_0065a0f0(*(undefined4 *)puVar6);
        if (iVar3 != 0) break;
        uVar2 = *puVar6;
        puVar6 = puVar6 + 2;
        *puVar4 = uVar2;
        puVar4 = puVar4 + 1;
        uVar7 = uVar7 + 1;
      } while (uVar7 < param_2);
    }
    break;
  case 0x10:
    uVar7 = 0;
    puVar6 = local_8;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a620(puVar6);
        }
        iVar3 = FUN_0065a110(*(undefined4 *)puVar6,*(undefined4 *)(puVar6 + 2));
        if (iVar3 != 0) break;
        uVar2 = *puVar6;
        puVar6 = puVar6 + 4;
        *puVar4 = uVar2;
        puVar4 = puVar4 + 1;
        uVar7 = uVar7 + 1;
      } while (uVar7 < param_2);
    }
    break;
  case 0x11:
    uVar7 = 0;
    puVar6 = local_8;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a620(puVar6);
        }
        iVar3 = FUN_0065a130(*(undefined4 *)puVar6,*(undefined4 *)(puVar6 + 2));
        if (iVar3 != 0) break;
        uVar2 = *puVar6;
        puVar6 = puVar6 + 4;
        *puVar4 = uVar2;
        puVar4 = puVar4 + 1;
        uVar7 = uVar7 + 1;
      } while (uVar7 < param_2);
    }
  }
  puVar4 = local_4;
  FUN_006507e0(local_8);
  if (iVar3 == 0) {
    *param_3 = puVar4;
    return 0;
  }
  FUN_006507e0(puVar4);
  return iVar3;
}

