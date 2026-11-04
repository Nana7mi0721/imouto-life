
int FUN_00657e10(int param_1,uint param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 extraout_ECX;
  undefined2 uVar5;
  undefined2 extraout_var;
  undefined4 extraout_ECX_00;
  undefined4 uVar4;
  undefined2 extraout_var_00;
  undefined4 extraout_ECX_01;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *local_8;
  undefined1 *local_4;
  
  uVar6 = param_2;
  switch(*(undefined2 *)(param_2 + 2)) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 6:
  case 7:
  case 8:
  case 9:
  case 0x10:
  case 0x11:
    break;
  default:
    return 2;
  }
  iVar2 = FUN_00655060(param_1,param_2,&param_2,1,&local_8);
  if ((iVar2 != 0) || (local_8 == (undefined4 *)0x0)) {
    *param_3 = 0;
    return iVar2;
  }
  switch(*(undefined2 *)(uVar6 + 2)) {
  case 6:
    uVar6 = 0;
    puVar7 = local_8;
    if (param_2 != 0) {
      do {
        iVar2 = FUN_0065a220(*(undefined1 *)puVar7);
        if (iVar2 != 0) {
          FUN_006507e0(local_8);
          return iVar2;
        }
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        uVar6 = uVar6 + 1;
      } while (uVar6 < param_2);
      *param_3 = local_8;
      return 0;
    }
  case 1:
  case 2:
  case 7:
    *param_3 = local_8;
    return 0;
  }
  puVar3 = (undefined1 *)FUN_006507d0(param_2);
  local_4 = puVar3;
  if (puVar3 == (undefined1 *)0x0) {
    FUN_006507e0(local_8);
    return 7;
  }
  iVar2 = 0;
  switch(*(undefined2 *)(uVar6 + 2)) {
  case 3:
    uVar6 = 0;
    uVar4 = extraout_ECX;
    puVar7 = local_8;
    if (param_2 != 0) {
      do {
        uVar5 = (undefined2)((uint)uVar4 >> 0x10);
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a5f0(puVar7);
          uVar5 = extraout_var;
        }
        iVar2 = FUN_00659f30(CONCAT22(uVar5,*(undefined2 *)puVar7));
        if (iVar2 != 0) break;
        uVar1 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 2);
        *puVar3 = uVar1;
        puVar3 = puVar3 + 1;
        uVar6 = uVar6 + 1;
        uVar4 = extraout_ECX_00;
      } while (uVar6 < param_2);
    }
    break;
  case 4:
    uVar6 = 0;
    puVar7 = local_8;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a600(puVar7);
        }
        iVar2 = FUN_00659f60(*puVar7);
        if (iVar2 != 0) break;
        uVar1 = *(undefined1 *)puVar7;
        puVar7 = puVar7 + 1;
        *puVar3 = uVar1;
        puVar3 = puVar3 + 1;
        uVar6 = uVar6 + 1;
      } while (uVar6 < param_2);
    }
    break;
  case 8:
    uVar6 = 0;
    uVar4 = extraout_ECX;
    puVar7 = local_8;
    if (param_2 != 0) {
      do {
        uVar5 = (undefined2)((uint)uVar4 >> 0x10);
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a5f0(puVar7);
          uVar5 = extraout_var_00;
        }
        iVar2 = FUN_00659f40(CONCAT22(uVar5,*(undefined2 *)puVar7));
        if (iVar2 != 0) break;
        uVar1 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 2);
        *puVar3 = uVar1;
        puVar3 = puVar3 + 1;
        uVar6 = uVar6 + 1;
        uVar4 = extraout_ECX_01;
      } while (uVar6 < param_2);
    }
    break;
  case 9:
    uVar6 = 0;
    puVar7 = local_8;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a600(puVar7);
        }
        iVar2 = FUN_00659f80(*puVar7);
        if (iVar2 != 0) break;
        uVar1 = *(undefined1 *)puVar7;
        puVar7 = puVar7 + 1;
        *puVar3 = uVar1;
        puVar3 = puVar3 + 1;
        uVar6 = uVar6 + 1;
      } while (uVar6 < param_2);
    }
    break;
  case 0x10:
    uVar6 = 0;
    puVar7 = local_8;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a620(puVar7);
        }
        iVar2 = FUN_00659fa0(*puVar7,puVar7[1]);
        if (iVar2 != 0) break;
        uVar1 = *(undefined1 *)puVar7;
        puVar7 = puVar7 + 2;
        *puVar3 = uVar1;
        puVar3 = puVar3 + 1;
        uVar6 = uVar6 + 1;
      } while (uVar6 < param_2);
    }
    break;
  case 0x11:
    uVar6 = 0;
    puVar7 = local_8;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a620(puVar7);
        }
        iVar2 = FUN_00659fc0(*puVar7,puVar7[1]);
        if (iVar2 != 0) break;
        uVar1 = *(undefined1 *)puVar7;
        puVar7 = puVar7 + 2;
        *puVar3 = uVar1;
        puVar3 = puVar3 + 1;
        uVar6 = uVar6 + 1;
      } while (uVar6 < param_2);
    }
  }
  FUN_006507e0(local_8);
  if (iVar2 == 0) {
    *param_3 = local_4;
    return 0;
  }
  FUN_006507e0(local_4);
  return iVar2;
}

