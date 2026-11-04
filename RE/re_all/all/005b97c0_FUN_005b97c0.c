
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b97c0(uint param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float local_2c;
  float local_28;
  float local_24;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (5 < param_1) {
    return 0xffffffff;
  }
  local_28 = *(float *)(DAT_00ef1b84 + 8);
  iVar1 = FUN_0056d3d0(&DAT_00f073a4 + param_1 * 0x1a,param_2,0x68);
  if ((iVar1 == 0) && (DAT_00ef7324 == 0)) {
    return 0;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  puVar2 = (undefined4 *)(param_1 * 0x70 + (int)local_28);
  puVar3 = param_2;
  puVar4 = &DAT_00f073a4 + param_1 * 0x1a;
  for (iVar1 = 0x1a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  local_28 = (float)param_2[0x18] * (float)_DAT_00804a60;
  FUN_0056d4d0(local_28,local_20,&local_24);
  local_28 = (float)param_2[0x19] * (float)_DAT_00804a60;
  FUN_0056d4d0(local_28,local_1c,&local_2c);
  *puVar2 = *param_2;
  FUN_00586200(&local_c,param_2 + 0x10,&DAT_00a383d8);
  FUN_00586170(&local_18,param_2 + 0xd,&DAT_00a383d8);
  puVar2[4] = local_18;
  puVar2[5] = local_14;
  puVar2[6] = local_10;
  puVar2[7] = (float)param_2[0x13] * (float)param_2[0x13];
  puVar2[8] = local_c;
  puVar2[9] = local_8;
  puVar2[10] = local_4;
  puVar2[0xb] = param_2[0x14];
  puVar2[0xc] = param_2[1];
  puVar2[0xd] = param_2[2];
  puVar2[0xe] = param_2[3];
  puVar2[0xf] = local_2c;
  puVar2[0x10] = param_2[5];
  puVar2[0x11] = param_2[6];
  puVar2[0x12] = param_2[7];
  puVar2[0x13] = 1.0 / (local_24 - local_2c);
  puVar2[0x14] = param_2[9];
  puVar2[0x15] = param_2[10];
  puVar2[0x16] = param_2[0xb];
  puVar2[0x17] = param_2[0xc];
  puVar2[0x18] = param_2[0x15];
  puVar2[0x19] = param_2[0x16];
  puVar2[0x1a] = param_2[0x17];
  *(undefined4 *)(DAT_00ef1b84 + 0xc) = 1;
  FUN_005b96d0();
  return 0;
}

