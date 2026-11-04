
undefined4
FUN_00518f40(int *param_1,int *param_2,int param_3,int param_4,int param_5,int param_6,int *param_7,
            int *param_8,int param_9)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 < param_3 + param_5) {
    if (((param_1[1] < param_4 + param_6) && (param_5 < param_1[8] + iVar1)) &&
       (param_6 < param_1[9] + param_1[1])) {
      if (param_5 < iVar1) {
        *param_7 = 0;
        *param_8 = *param_1 - param_5;
      }
      else {
        *param_7 = param_5 - iVar1;
        *param_8 = 0;
      }
      if (param_1[8] + *param_1 < param_3 + param_5) {
        param_7[2] = param_1[8];
        param_8[2] = (param_1[8] - param_5) + *param_1;
      }
      else {
        param_7[2] = (param_3 - *param_1) + param_5;
        param_8[2] = param_3;
      }
      if (param_6 < param_1[1]) {
        param_7[1] = 0;
        param_8[1] = param_1[1] - param_6;
      }
      else {
        param_7[1] = param_6 - param_1[1];
        param_8[1] = 0;
      }
      if (param_1[9] + param_1[1] < param_4 + param_6) {
        param_7[3] = param_1[9];
        param_4 = (param_1[9] - param_6) + param_1[1];
      }
      else {
        param_7[3] = (param_4 - param_1[1]) + param_6;
      }
      param_8[3] = param_4;
      *param_7 = *param_7 + param_1[4];
      param_7[1] = param_7[1] + param_1[5];
      param_7[2] = param_7[2] + param_1[4];
      param_7[3] = param_7[3] + param_1[5];
      *param_8 = *param_8 + *param_2;
      param_8[1] = param_8[1] + param_2[1];
      param_8[2] = param_8[2] + *param_2;
      param_8[3] = param_8[3] + param_2[1];
      if (param_9 != 0) {
        *param_7 = ((int)(*param_7 + 3 + (*param_7 + 3 >> 0x1f & 3U)) >> 2) * 4;
        param_7[1] = ((int)(param_7[1] + 3 + (param_7[1] + 3 >> 0x1f & 3U)) >> 2) * 4;
        param_7[2] = ((int)(param_7[2] + 3 + (param_7[2] + 3 >> 0x1f & 3U)) >> 2) * 4;
        param_7[3] = ((int)(param_7[3] + 3 + (param_7[3] + 3 >> 0x1f & 3U)) >> 2) * 4;
        *param_8 = ((int)(*param_8 + 3 + (*param_8 + 3 >> 0x1f & 3U)) >> 2) * 4;
        param_8[1] = ((int)(param_8[1] + 3 + (param_8[1] + 3 >> 0x1f & 3U)) >> 2) * 4;
        param_8[2] = ((int)(param_8[2] + 3 + (param_8[2] + 3 >> 0x1f & 3U)) >> 2) * 4;
        param_8[3] = ((int)(param_8[3] + 3 + (param_8[3] + 3 >> 0x1f & 3U)) >> 2) * 4;
      }
      return 0;
    }
  }
  return 0xffffffff;
}

