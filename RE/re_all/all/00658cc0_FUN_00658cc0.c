
int FUN_00658cc0(int param_1,uint param_2,undefined4 *param_3)

{
  short sVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  uint *local_8;
  int local_4;
  
  uVar6 = param_2;
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
  local_4 = FUN_00655060(param_1,param_2,&param_2,4,&local_8);
  if ((local_4 != 0) || (local_8 == (uint *)0x0)) {
    *param_3 = 0;
    return local_4;
  }
  sVar1 = *(short *)(uVar6 + 2);
  if (sVar1 == 4) {
    uVar6 = 0;
    local_4 = 0;
    puVar3 = local_8;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a600(puVar3);
        }
        iVar4 = FUN_0065a1b0(*puVar3);
        if (iVar4 != 0) {
          FUN_006507e0(local_8);
          return iVar4;
        }
        puVar3 = puVar3 + 1;
        uVar6 = uVar6 + 1;
      } while (uVar6 < param_2);
    }
    *param_3 = local_8;
    return 0;
  }
  if (sVar1 == 9) {
    *param_3 = local_8;
    if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
      FUN_0065a6c0(local_8,param_2);
    }
    return 0;
  }
  puVar3 = (uint *)FUN_006507d0(param_2 * 4);
  if (puVar3 == (uint *)0x0) {
    FUN_006507e0(local_8);
    return 7;
  }
  switch(*(undefined2 *)(uVar6 + 2)) {
  case 1:
    uVar6 = 0;
    puVar7 = puVar3;
    puVar5 = local_8;
    if (param_2 != 0) {
      do {
        uVar2 = *puVar5;
        puVar5 = (uint *)((int)puVar5 + 1);
        *puVar7 = (uint)(byte)uVar2;
        uVar6 = uVar6 + 1;
        puVar7 = puVar7 + 1;
      } while (uVar6 < param_2);
    }
    break;
  case 3:
    uVar6 = 0;
    puVar7 = local_8;
    puVar5 = puVar3;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a5f0(puVar7);
        }
        uVar2 = *puVar7;
        puVar7 = (uint *)((int)puVar7 + 2);
        *puVar5 = (uint)(ushort)uVar2;
        uVar6 = uVar6 + 1;
        puVar5 = puVar5 + 1;
      } while (uVar6 < param_2);
    }
    break;
  case 6:
    uVar6 = 0;
    puVar7 = puVar3;
    puVar5 = local_8;
    if (param_2 != 0) {
      do {
        *puVar7 = (int)(char)(byte)*puVar5;
        puVar7 = puVar7 + 1;
        puVar5 = (uint *)((int)puVar5 + 1);
        uVar6 = uVar6 + 1;
      } while (uVar6 < param_2);
    }
    break;
  case 8:
    uVar6 = 0;
    puVar7 = local_8;
    puVar5 = puVar3;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a5f0(puVar7);
        }
        *puVar5 = (int)(short)(ushort)*puVar7;
        puVar5 = puVar5 + 1;
        puVar7 = (uint *)((int)puVar7 + 2);
        uVar6 = uVar6 + 1;
      } while (uVar6 < param_2);
    }
    break;
  case 0x10:
    uVar6 = 0;
    puVar7 = local_8;
    puVar5 = puVar3;
    iVar4 = local_4;
    if (param_2 != 0) {
      do {
        local_4 = iVar4;
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a620(puVar7);
        }
        local_4 = FUN_0065a1d0(*puVar7,puVar7[1]);
        if (local_4 != 0) break;
        uVar2 = *puVar7;
        puVar7 = puVar7 + 2;
        *puVar5 = uVar2;
        puVar5 = puVar5 + 1;
        uVar6 = uVar6 + 1;
        iVar4 = 0;
      } while (uVar6 < param_2);
    }
    break;
  case 0x11:
    uVar6 = 0;
    puVar7 = local_8;
    puVar5 = puVar3;
    iVar4 = local_4;
    if (param_2 != 0) {
      do {
        local_4 = iVar4;
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a620(puVar7);
        }
        local_4 = FUN_0065a1f0(*puVar7,puVar7[1]);
        if (local_4 != 0) break;
        uVar2 = *puVar7;
        puVar7 = puVar7 + 2;
        *puVar5 = uVar2;
        puVar5 = puVar5 + 1;
        uVar6 = uVar6 + 1;
        iVar4 = 0;
      } while (uVar6 < param_2);
    }
  }
  FUN_006507e0(local_8);
  iVar4 = local_4;
  if (local_4 == 0) {
    *param_3 = puVar3;
    return 0;
  }
  FUN_006507e0(puVar3);
  return iVar4;
}

