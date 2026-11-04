
undefined4 FUN_00799b00(int *param_1)

{
  byte *pbVar1;
  
  if (0xff < param_1[2] + param_1[1]) {
    return 0;
  }
  if (0 < *param_1) {
    pbVar1 = (byte *)(param_1 + 3);
    do {
      if ((param_1[2] + param_1[1] <= (int)(uint)*pbVar1) && (*pbVar1 != 0xff)) {
        return 0;
      }
      pbVar1 = pbVar1 + 1;
    } while ((int)(pbVar1 + (-0xc - (int)param_1)) < *param_1);
  }
  return 1;
}

