
void FUN_00597580(int param_1,int param_2,int param_3,char *param_4,char *param_5,char *param_6)

{
  int iVar1;
  
  if (param_1 + param_2 + param_3 == 0) {
    *param_4 = -1;
    *param_5 = -1;
    *param_6 = -1;
    return;
  }
  if (0xff < param_1) {
    param_1 = 0xff;
  }
  if (0xff < param_2) {
    param_2 = 0xff;
  }
  if (0xff < param_3) {
    param_3 = 0xff;
  }
  if (param_2 < param_1) {
    if (param_3 < param_1) {
      if (param_3 < param_2) {
        iVar1 = ((param_1 - param_3) * 0xff) / param_1;
        *param_4 = -1;
        *param_5 = -1 - (char)(((((param_3 - param_2) * 0xff) / (param_1 - param_3) + 0xff) * iVar1)
                              / 0xff);
        *param_6 = -1 - (char)iVar1;
        return;
      }
      iVar1 = ((param_1 - param_2) * 0xff) / param_1;
      *param_4 = -1;
      *param_5 = -1 - (char)iVar1;
      *param_6 = -1 - (char)(((((param_2 - param_3) * 0xff) / (param_1 - param_2) + 0xff) * iVar1) /
                            0xff);
      return;
    }
    if (param_3 != param_2) {
      iVar1 = ((param_3 - param_2) * 0xff) / param_3;
      *param_4 = -1 - (char)(((((param_2 - param_1) * 0xff) / (param_3 - param_2) + 0xff) * iVar1) /
                            0xff);
      *param_5 = -1 - (char)iVar1;
      *param_6 = -1;
      return;
    }
  }
  else {
    if (param_2 <= param_3) {
      if (param_3 == param_1) {
        *param_4 = -1;
        *param_5 = -1;
        *param_6 = -1;
        return;
      }
      iVar1 = ((param_3 - param_1) * 0xff) / param_3;
      *param_4 = -1 - (char)iVar1;
      *param_5 = -1 - (char)(((((param_1 - param_2) * 0xff) / (param_3 - param_1) + 0xff) * iVar1) /
                            0xff);
      *param_6 = -1;
      return;
    }
    if (param_3 < param_1) {
      if (param_2 != param_3) {
        iVar1 = ((param_2 - param_3) * 0xff) / param_2;
        *param_4 = -1 - (char)(((((param_3 - param_1) * 0xff) / (param_2 - param_3) + 0xff) * iVar1)
                              / 0xff);
        *param_5 = -1;
        *param_6 = -1 - (char)iVar1;
        return;
      }
    }
    else if (param_2 != param_1) {
      iVar1 = ((param_2 - param_1) * 0xff) / param_2;
      *param_4 = -1 - (char)iVar1;
      *param_5 = -1;
      *param_6 = -1 - (char)(((((param_1 - param_3) * 0xff) / (param_2 - param_1) + 0xff) * iVar1) /
                            0xff);
      return;
    }
  }
  *param_4 = -1;
  *param_5 = -1;
  *param_6 = -1;
  return;
}

