
int FUN_006593c0(int param_1,uint param_2,undefined4 *param_3)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  uint *local_4;
  
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
  iVar3 = FUN_00655060(param_1,param_2,&param_2,8,&local_4);
  if ((iVar3 != 0) || (local_4 == (uint *)0x0)) {
    *param_3 = 0;
    return iVar3;
  }
  sVar1 = *(short *)(uVar6 + 2);
  if (sVar1 == 0x10) {
    uVar6 = 0;
    puVar4 = local_4;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a620(puVar4);
        }
        iVar3 = FUN_0065a270(*puVar4,puVar4[1]);
        if (iVar3 != 0) {
          FUN_006507e0(local_4);
          return iVar3;
        }
        puVar4 = puVar4 + 2;
        uVar6 = uVar6 + 1;
      } while (uVar6 < param_2);
    }
    *param_3 = local_4;
    return 0;
  }
  if (sVar1 == 0x11) {
    *param_3 = local_4;
    if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
      FUN_0065a700(local_4,param_2);
    }
    return 0;
  }
  puVar4 = (uint *)FUN_006507d0(param_2 * 8);
  if (puVar4 == (uint *)0x0) {
    FUN_006507e0(local_4);
    return 7;
  }
  switch(*(undefined2 *)(uVar6 + 2)) {
  case 1:
    uVar6 = 0;
    puVar5 = puVar4;
    puVar7 = local_4;
    if (param_2 != 0) {
      do {
        uVar2 = *puVar7;
        puVar7 = (uint *)((int)puVar7 + 1);
        *puVar5 = (uint)(byte)uVar2;
        puVar5[1] = 0;
        uVar6 = uVar6 + 1;
        puVar5 = puVar5 + 2;
      } while (uVar6 < param_2);
    }
    break;
  case 3:
    uVar6 = 0;
    puVar5 = puVar4;
    puVar7 = local_4;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a5f0(puVar7);
        }
        uVar2 = *puVar7;
        puVar7 = (uint *)((int)puVar7 + 2);
        *puVar5 = (uint)(ushort)uVar2;
        puVar5[1] = 0;
        uVar6 = uVar6 + 1;
        puVar5 = puVar5 + 2;
      } while (uVar6 < param_2);
    }
    break;
  case 4:
    uVar6 = 0;
    puVar5 = puVar4;
    puVar7 = local_4;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a600(puVar7);
        }
        uVar2 = *puVar7;
        puVar7 = puVar7 + 1;
        *puVar5 = uVar2;
        puVar5[1] = 0;
        puVar5 = puVar5 + 2;
        uVar6 = uVar6 + 1;
      } while (uVar6 < param_2);
    }
    break;
  case 6:
    uVar6 = 0;
    puVar5 = puVar4;
    puVar7 = local_4;
    if (param_2 != 0) {
      do {
        uVar2 = *puVar7;
        *puVar5 = (int)(char)(byte)uVar2;
        puVar5[1] = (int)(char)(byte)uVar2 >> 0x1f;
        puVar5 = puVar5 + 2;
        puVar7 = (uint *)((int)puVar7 + 1);
        uVar6 = uVar6 + 1;
      } while (uVar6 < param_2);
    }
    break;
  case 8:
    uVar6 = 0;
    puVar5 = puVar4;
    puVar7 = local_4;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a5f0(puVar7);
        }
        uVar2 = *puVar7;
        *puVar5 = (int)(short)(ushort)uVar2;
        puVar5[1] = (int)(short)(ushort)uVar2 >> 0x1f;
        puVar5 = puVar5 + 2;
        puVar7 = (uint *)((int)puVar7 + 2);
        uVar6 = uVar6 + 1;
      } while (uVar6 < param_2);
    }
    break;
  case 9:
    uVar6 = 0;
    puVar5 = puVar4;
    puVar7 = local_4;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a600(puVar7);
        }
        uVar2 = *puVar7;
        *puVar5 = uVar2;
        puVar5[1] = (int)uVar2 >> 0x1f;
        puVar7 = puVar7 + 1;
        uVar6 = uVar6 + 1;
        puVar5 = puVar5 + 2;
      } while (uVar6 < param_2);
    }
  }
  FUN_006507e0(local_4);
  *param_3 = puVar4;
  return 0;
}

