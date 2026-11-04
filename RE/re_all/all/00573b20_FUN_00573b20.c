
undefined4 FUN_00573b20(int *param_1,uint *param_2,int *param_3)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = (byte *)*param_1;
  bVar1 = *pbVar2;
  if ((char)bVar1 < '\0') {
    if ((bVar1 & 0xe0) == 0xc0) {
      *param_2 = pbVar2[1] & 0x3f | (*pbVar2 & 0x1f) << 6;
      *param_1 = *param_1 + 2;
      *param_3 = *param_3 + 2;
      return 1;
    }
    if ((bVar1 & 0xf0) == 0xe0) {
      *param_2 = (pbVar2[1] & 0x3f | (*pbVar2 & 0xf) << 6) << 6 | pbVar2[2] & 0x3f;
      *param_1 = *param_1 + 3;
      *param_3 = *param_3 + 3;
      return 1;
    }
    if ((bVar1 & 0xf8) == 0xf0) {
      *param_2 = ((pbVar2[1] & 0x3f | (*pbVar2 & 7) << 6) << 6 | pbVar2[2] & 0x3f) << 6 |
                 pbVar2[3] & 0x3f;
      *param_1 = *param_1 + 4;
      *param_3 = *param_3 + 4;
      return 1;
    }
    if ((bVar1 & 0xfc) == 0xf8) {
      *param_2 = (((pbVar2[1] & 0x3f | (*pbVar2 & 3) << 6) << 6 | pbVar2[2] & 0x3f) << 6 |
                 pbVar2[3] & 0x3f) << 6 | pbVar2[4] & 0x3f;
      *param_1 = *param_1 + 5;
      *param_3 = *param_3 + 5;
      return 1;
    }
    if ((bVar1 & 0xfe) == 0xfc) {
      *param_2 = ((((pbVar2[1] & 0x3f | (*pbVar2 & 1) << 6) << 6 | pbVar2[2] & 0x3f) << 6 |
                  pbVar2[3] & 0x3f) << 6 | pbVar2[4] & 0x3f) << 6 | pbVar2[5] & 0x3f;
      *param_1 = *param_1 + 6;
      *param_3 = *param_3 + 6;
      return 1;
    }
  }
  else {
    *param_2 = (uint)bVar1;
    if (bVar1 != 0) {
      *param_1 = *param_1 + 1;
      *param_3 = *param_3 + 1;
      return 1;
    }
  }
  return 0;
}

