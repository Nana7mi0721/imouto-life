
int FUN_006581d0(int param_1,uint param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  short sVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined2 uVar5;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *local_8;
  undefined1 *local_4;
  
  uVar6 = param_2;
  switch(*(undefined2 *)(param_2 + 2)) {
  case 1:
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
  iVar3 = FUN_00655060(param_1,param_2,&param_2,1,&local_8);
  if ((iVar3 != 0) || (local_8 == (undefined4 *)0x0)) {
    *param_3 = 0;
    return iVar3;
  }
  sVar2 = *(short *)(uVar6 + 2);
  if (sVar2 != 1) {
    if (sVar2 == 6) goto LAB_006584ad;
    if (sVar2 != 7) {
      puVar4 = (undefined1 *)FUN_006507d0(param_2);
      local_4 = puVar4;
      if (puVar4 == (undefined1 *)0x0) {
        FUN_006507e0(local_8);
        return 7;
      }
      iVar3 = 0;
      switch(*(undefined2 *)(uVar6 + 2)) {
      case 3:
        uVar6 = 0;
        puVar7 = local_8;
        if (param_2 != 0) {
          do {
            uVar5 = (undefined2)(param_2 >> 0x10);
            if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
              FUN_0065a5f0(puVar7);
              uVar5 = extraout_var;
            }
            iVar3 = FUN_0065a000(CONCAT22(uVar5,*(undefined2 *)puVar7));
            if (iVar3 != 0) break;
            uVar1 = *(undefined1 *)puVar7;
            puVar7 = (undefined4 *)((int)puVar7 + 2);
            *puVar4 = uVar1;
            puVar4 = puVar4 + 1;
            uVar6 = uVar6 + 1;
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
            iVar3 = FUN_0065a030(*puVar7);
            if (iVar3 != 0) break;
            uVar1 = *(undefined1 *)puVar7;
            puVar7 = puVar7 + 1;
            *puVar4 = uVar1;
            puVar4 = puVar4 + 1;
            uVar6 = uVar6 + 1;
          } while (uVar6 < param_2);
        }
        break;
      case 8:
        uVar6 = 0;
        puVar7 = local_8;
        if (param_2 != 0) {
          do {
            uVar5 = (undefined2)(param_2 >> 0x10);
            if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
              FUN_0065a5f0(puVar7);
              uVar5 = extraout_var_00;
            }
            iVar3 = FUN_0065a010(CONCAT22(uVar5,*(undefined2 *)puVar7));
            if (iVar3 != 0) break;
            uVar1 = *(undefined1 *)puVar7;
            puVar7 = (undefined4 *)((int)puVar7 + 2);
            *puVar4 = uVar1;
            puVar4 = puVar4 + 1;
            uVar6 = uVar6 + 1;
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
            iVar3 = FUN_0065a050(*puVar7);
            if (iVar3 != 0) break;
            uVar1 = *(undefined1 *)puVar7;
            puVar7 = puVar7 + 1;
            *puVar4 = uVar1;
            puVar4 = puVar4 + 1;
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
            iVar3 = FUN_0065a070(*puVar7,puVar7[1]);
            if (iVar3 != 0) break;
            uVar1 = *(undefined1 *)puVar7;
            puVar7 = puVar7 + 2;
            *puVar4 = uVar1;
            puVar4 = puVar4 + 1;
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
            iVar3 = FUN_0065a090(*puVar7,puVar7[1]);
            if (iVar3 != 0) break;
            uVar1 = *(undefined1 *)puVar7;
            puVar7 = puVar7 + 2;
            *puVar4 = uVar1;
            puVar4 = puVar4 + 1;
            uVar6 = uVar6 + 1;
          } while (uVar6 < param_2);
        }
      }
      FUN_006507e0(local_8);
      if (iVar3 == 0) {
        *param_3 = local_4;
        return 0;
      }
      FUN_006507e0(local_4);
      return iVar3;
    }
  }
  uVar6 = 0;
  puVar7 = local_8;
  if (param_2 != 0) {
    do {
      iVar3 = FUN_00659ff0(*(undefined1 *)puVar7);
      if (iVar3 != 0) {
        FUN_006507e0(local_8);
        return iVar3;
      }
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      uVar6 = uVar6 + 1;
    } while (uVar6 < param_2);
    *param_3 = local_8;
    return 0;
  }
LAB_006584ad:
  *param_3 = local_8;
  return 0;
}

