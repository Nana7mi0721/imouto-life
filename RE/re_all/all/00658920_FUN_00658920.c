
int FUN_00658920(int param_1,uint param_2,undefined4 *param_3)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 extraout_var;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  uint *local_8;
  uint *local_4;
  
  uVar5 = param_2;
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
  iVar3 = FUN_00655060(param_1,param_2,&param_2,4,&local_8);
  if ((iVar3 != 0) || (local_8 == (uint *)0x0)) {
    *param_3 = 0;
    return iVar3;
  }
  sVar1 = *(short *)(uVar5 + 2);
  if (sVar1 == 4) {
    *param_3 = local_8;
    if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
      FUN_0065a6c0(local_8,param_2);
    }
    return 0;
  }
  if (sVar1 == 9) {
    uVar5 = 0;
    puVar7 = local_8;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a600(puVar7);
        }
        iVar3 = FUN_0065a240(*puVar7);
        if (iVar3 != 0) {
          FUN_006507e0(local_8);
          return iVar3;
        }
        puVar7 = puVar7 + 1;
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_2);
    }
    *param_3 = local_8;
    return 0;
  }
  uVar8 = FUN_006507d0(param_2 * 4);
  puVar7 = (uint *)uVar8;
  local_4 = puVar7;
  if (puVar7 == (uint *)0x0) {
    FUN_006507e0(local_8);
    return 7;
  }
  iVar3 = 0;
  switch(*(undefined2 *)(uVar5 + 2)) {
  case 1:
    uVar5 = 0;
    puVar6 = local_8;
    if (param_2 != 0) {
      do {
        uVar2 = *puVar6;
        puVar6 = (uint *)((int)puVar6 + 1);
        *puVar7 = (uint)(byte)uVar2;
        uVar5 = uVar5 + 1;
        puVar7 = puVar7 + 1;
      } while (uVar5 < param_2);
    }
    break;
  case 3:
    uVar5 = 0;
    puVar6 = local_8;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a5f0(puVar6);
        }
        uVar2 = *puVar6;
        puVar6 = (uint *)((int)puVar6 + 2);
        *puVar7 = (uint)(ushort)uVar2;
        uVar5 = uVar5 + 1;
        puVar7 = puVar7 + 1;
      } while (uVar5 < param_2);
    }
    break;
  case 6:
    uVar5 = 0;
    puVar6 = local_8;
    if (param_2 != 0) {
      do {
        iVar3 = FUN_0065a220((byte)*puVar6);
        if (iVar3 != 0) break;
        *puVar7 = (int)(char)(byte)*puVar6;
        puVar7 = puVar7 + 1;
        puVar6 = (uint *)((int)puVar6 + 1);
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_2);
    }
    break;
  case 8:
    uVar5 = 0;
    puVar7 = local_8;
    if (param_2 != 0) {
      do {
        uVar4 = (undefined2)((ulonglong)uVar8 >> 0x30);
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a5f0(puVar7);
          uVar4 = extraout_var;
        }
        uVar9 = FUN_0065a230(CONCAT22(uVar4,(ushort)*puVar7));
        iVar3 = (int)uVar9;
        if (iVar3 != 0) break;
        *(int *)uVar8 = (int)(short)(ushort)*puVar7;
        uVar8 = CONCAT44((int)((ulonglong)uVar9 >> 0x20),(int *)uVar8 + 1);
        puVar7 = (uint *)((int)puVar7 + 2);
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_2);
    }
    break;
  case 0x10:
    uVar5 = 0;
    puVar6 = local_8;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a620(puVar6);
        }
        iVar3 = FUN_0065a160(*puVar6,puVar6[1]);
        if (iVar3 != 0) break;
        uVar2 = *puVar6;
        puVar6 = puVar6 + 2;
        *puVar7 = uVar2;
        puVar7 = puVar7 + 1;
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_2);
    }
    break;
  case 0x11:
    uVar5 = 0;
    puVar6 = local_8;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a620(puVar6);
        }
        iVar3 = FUN_0065a180(*puVar6,puVar6[1]);
        if (iVar3 != 0) break;
        uVar2 = *puVar6;
        puVar6 = puVar6 + 2;
        *puVar7 = uVar2;
        puVar7 = puVar7 + 1;
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_2);
    }
  }
  puVar7 = local_4;
  FUN_006507e0(local_8);
  if (iVar3 == 0) {
    *param_3 = puVar7;
    return 0;
  }
  FUN_006507e0(puVar7);
  return iVar3;
}

