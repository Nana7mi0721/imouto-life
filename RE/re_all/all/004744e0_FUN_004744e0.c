
undefined4 * __thiscall FUN_004744e0(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  *param_1 = *param_2;
  FUN_004cb840(param_2 + 1);
  FUN_004cb840(param_2 + 8);
  FUN_004cb840(param_2 + 0xf);
  FUN_004cb840(param_2 + 0x16);
  FUN_004cb840(param_2 + 0x1d);
  param_1[0x24] = param_2[0x24];
  param_1[0x25] = param_2[0x25];
  param_1[0x26] = param_2[0x26];
  param_1[0x27] = param_2[0x27];
  param_1[0x28] = param_2[0x28];
  param_1[0x29] = param_2[0x29];
  param_1[0x2a] = param_2[0x2a];
  param_1[0x2b] = param_2[0x2b];
  param_1[0x2c] = param_2[0x2c];
  param_1[0x2d] = param_2[0x2d];
  param_1[0x2e] = param_2[0x2e];
  *(undefined1 *)(param_1 + 0x2f) = *(undefined1 *)(param_2 + 0x2f);
  *(undefined1 *)((int)param_1 + 0xbd) = *(undefined1 *)((int)param_2 + 0xbd);
  *(undefined1 *)((int)param_1 + 0xbe) = *(undefined1 *)((int)param_2 + 0xbe);
  *(undefined1 *)((int)param_1 + 0xbf) = *(undefined1 *)((int)param_2 + 0xbf);
  *(undefined1 *)(param_1 + 0x30) = *(undefined1 *)(param_2 + 0x30);
  *(undefined1 *)((int)param_1 + 0xc1) = *(undefined1 *)((int)param_2 + 0xc1);
  *(undefined1 *)((int)param_1 + 0xc2) = *(undefined1 *)((int)param_2 + 0xc2);
  *(undefined1 *)((int)param_1 + 0xc3) = *(undefined1 *)((int)param_2 + 0xc3);
  *(undefined1 *)(param_1 + 0x31) = *(undefined1 *)(param_2 + 0x31);
  param_1[0x32] = param_2[0x32];
  param_1[0x33] = param_2[0x33];
  param_1[0x34] = param_2[0x34];
  param_1[0x35] = param_2[0x35];
  param_1[0x36] = param_2[0x36];
  param_1[0x37] = param_2[0x37];
  param_1[0x38] = param_2[0x38];
  param_1[0x39] = param_2[0x39];
  param_1[0x3a] = param_2[0x3a];
  param_1[0x3b] = param_2[0x3b];
  *(undefined1 *)(param_1 + 0x3c) = *(undefined1 *)(param_2 + 0x3c);
  *(undefined1 *)((int)param_1 + 0xf1) = *(undefined1 *)((int)param_2 + 0xf1);
  *(undefined1 *)((int)param_1 + 0xf2) = *(undefined1 *)((int)param_2 + 0xf2);
  *(undefined1 *)((int)param_1 + 0xf3) = *(undefined1 *)((int)param_2 + 0xf3);
  *(undefined1 *)(param_1 + 0x3d) = *(undefined1 *)(param_2 + 0x3d);
  param_1[0x3e] = param_2[0x3e];
  param_1[0x3f] = param_2[0x3f];
  param_1[0x40] = param_2[0x40];
  param_1[0x41] = param_2[0x41];
  *(undefined1 *)(param_1 + 0x42) = *(undefined1 *)(param_2 + 0x42);
  *(undefined1 *)((int)param_1 + 0x109) = *(undefined1 *)((int)param_2 + 0x109);
  param_1[0x43] = param_2[0x43];
  param_1[0x44] = param_2[0x44];
  param_1[0x45] = param_2[0x45];
  *(undefined1 *)(param_1 + 0x46) = *(undefined1 *)(param_2 + 0x46);
  *(undefined1 *)((int)param_1 + 0x119) = *(undefined1 *)((int)param_2 + 0x119);
  param_1[0x47] = param_2[0x47];
  param_1[0x48] = param_2[0x48];
  *(undefined1 *)(param_1 + 0x49) = *(undefined1 *)(param_2 + 0x49);
  *(undefined1 *)((int)param_1 + 0x125) = *(undefined1 *)((int)param_2 + 0x125);
  param_1[0x4a] = param_2[0x4a];
  *(undefined1 *)(param_1 + 0x4b) = *(undefined1 *)(param_2 + 0x4b);
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    param_1[local_8 + 0x4c] = param_2[local_8 + 0x4c];
  }
  for (local_c = 0; local_c < 5; local_c = local_c + 1) {
    param_1[local_c * 2 + 0x52] = param_2[local_c * 2 + 0x52];
    param_1[local_c * 2 + 0x53] = param_2[local_c * 2 + 0x53];
  }
  puVar2 = param_2 + 0x5c;
  puVar3 = param_1 + 0x5c;
  for (iVar1 = 0x25; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_004cb840(param_2 + 0x81);
  FUN_004cb840(param_2 + 0x88);
  FUN_004cb840(param_2 + 0x8f);
  *(undefined1 *)(param_1 + 0x96) = *(undefined1 *)(param_2 + 0x96);
  for (local_10 = 0; local_10 < 10; local_10 = local_10 + 1) {
    FUN_004cb840(param_2 + local_10 * 7 + 0x97);
  }
  param_1[0xdd] = param_2[0xdd];
  param_1[0xde] = param_2[0xde];
  *(undefined1 *)(param_1 + 0xdf) = *(undefined1 *)(param_2 + 0xdf);
  param_1[0xe0] = param_2[0xe0];
  param_1[0xe1] = param_2[0xe1];
  for (local_14 = 0; local_14 < 3; local_14 = local_14 + 1) {
    param_1[local_14 + 0xe2] = param_2[local_14 + 0xe2];
  }
  for (local_18 = 0; local_18 < 3; local_18 = local_18 + 1) {
    param_1[local_18 + 0xe5] = param_2[local_18 + 0xe5];
  }
  *(undefined1 *)(param_1 + 0xe8) = *(undefined1 *)(param_2 + 0xe8);
  *(undefined1 *)((int)param_1 + 0x3a1) = *(undefined1 *)((int)param_2 + 0x3a1);
  param_1[0xe9] = param_2[0xe9];
  param_1[0xea] = param_2[0xea];
  param_1[0xeb] = param_2[0xeb];
  param_1[0xec] = param_2[0xec];
  param_1[0xed] = param_2[0xed];
  param_1[0xee] = param_2[0xee];
  param_1[0xef] = param_2[0xef];
  param_1[0xf0] = param_2[0xf0];
  param_1[0xf1] = param_2[0xf1];
  return param_1;
}

