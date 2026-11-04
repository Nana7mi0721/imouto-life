
undefined4 __fastcall FUN_005dc090(byte *param_1,char *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  
  if ((*param_2 != -1) || ((param_2[1] & 0xe0U) != 0xe0)) {
    return 0xfffffffe;
  }
  param_1[1] = 0;
  bVar2 = (byte)param_2[1] >> 3 & 3;
  if (((byte)param_2[1] >> 3 & 3) == 0) {
    param_1[1] = 2;
  }
  else if (bVar2 == 2) {
    param_1[1] = 1;
  }
  else {
    if (bVar2 != 3) {
      return 0xffffffff;
    }
    param_1[1] = 0;
  }
  *param_1 = 0xff;
  bVar2 = (byte)param_2[1] >> 1 & 3;
  if (bVar2 == 1) {
    *param_1 = 2;
  }
  else if (bVar2 == 2) {
    *param_1 = 1;
  }
  else if (bVar2 == 3) {
    *param_1 = 0;
  }
  bVar2 = (byte)param_2[2] >> 4;
  param_1[2] = bVar2;
  if (0xe < bVar2) {
    return 0xffffffff;
  }
  bVar1 = *param_1;
  *(undefined4 *)(param_1 + 0xc) =
       *(undefined4 *)
        (&DAT_00889cb0 + (((uint)param_1[1] * 3 + (uint)bVar1) * 0x10 + (uint)bVar2) * 4);
  bVar2 = param_2[2];
  bVar3 = bVar2 >> 2 & 3;
  param_1[3] = bVar3;
  if (2 < bVar3) {
    return 0xffffffff;
  }
  *(undefined4 *)(param_1 + 8) =
       *(undefined4 *)(&DAT_00889ef0 + ((bVar2 >> 2 & 3) + (uint)param_1[1] * 4) * 4);
  param_1[4] = (byte)param_2[2] >> 1 & 1;
  param_1[5] = ((param_2[3] & 0xc0U) != 0xc0) + 1;
  if (bVar1 == 0) {
    param_1[0x14] = 0x60;
    param_1[0x15] = 0;
    param_1[0x16] = 0;
    param_1[0x17] = 0;
    *(uint *)(param_1 + 0x10) =
         ((uint)(*(int *)(param_1 + 0xc) * 12000) / *(uint *)(param_1 + 8) + (uint)param_1[4]) * 4;
  }
  else if ((byte)(bVar1 - 1) < 2) {
    param_1[0x14] = 0x80;
    param_1[0x15] = 4;
    param_1[0x16] = 0;
    param_1[0x17] = 0;
    *(uint *)(param_1 + 0x10) =
         (uint)(*(int *)(param_1 + 0xc) * 0x23280) / *(uint *)(param_1 + 8) + (uint)param_1[4];
    return 0;
  }
  return 0;
}

