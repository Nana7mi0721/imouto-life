
undefined4
FUN_00517450(char *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            char param_8,int param_9)

{
  char cVar1;
  int iVar2;
  
  FUN_0056d380(param_1,0,0x13);
  *param_1 = (char)DAT_00a37d78;
  param_1[5] = *(char *)(param_2 + 0x24);
  param_1[1] = *(char *)(param_2 + 0x1c);
  param_1[6] = *(char *)(param_2 + 0x28);
  param_1[7] = *(char *)(param_2 + 0x2c);
  param_1[8] = param_8;
  if (param_9 == -1) {
    param_9 = *(int *)(param_2 + 0x54);
    if (param_9 == -1) {
      param_1[9] = '\x01';
      while ((param_3 != 1 || (param_4 != 1))) {
        param_1[9] = param_1[9] + '\x01';
        param_3 = param_3 / 2;
        param_4 = param_4 / 2;
        if (param_3 == 0) {
          param_3 = 1;
        }
        if (param_4 == 0) {
          param_4 = 1;
        }
      }
      goto LAB_005174f2;
    }
    if (param_9 == 0) {
      param_9 = 1;
    }
  }
  param_1[9] = (char)param_9;
LAB_005174f2:
  if (*(int *)(param_2 + 0x30) == 1) {
    param_1[3] = '\x01';
    param_1[2] = *(char *)(param_2 + 0x34);
    param_1[10] = '\0';
    param_1[0xf] = '\0';
    param_1[5] = '\0';
    param_1[9] = '\x01';
  }
  else {
    param_1[3] = '\0';
    param_1[2] = (char)param_5;
    param_1[10] = *(char *)(param_2 + 0x14);
    param_1[0xf] = *(char *)(param_2 + 0x20);
  }
  if (*param_1 == '\x01') {
    iVar2 = *(int *)(param_2 + 4);
    if ((*(int *)(param_2 + 4) == 0) && (iVar2 = 0x20, param_5 != 1)) {
      iVar2 = DAT_00a37e70;
    }
    param_1[0xc] = (char)iVar2;
    param_1[0xd] = *(char *)(param_2 + 0xc);
    if (*(int *)(param_2 + 0xc) < 1) {
      cVar1 = '\0';
    }
    else {
      cVar1 = (char)*(undefined4 *)(param_2 + 0x10);
    }
    param_1[0xe] = cVar1;
    param_1[0xb] = *(char *)(param_2 + 8);
    param_1[4] = '\0';
    if (param_1[2] != '\0') {
      param_1[10] = '\0';
    }
    if (param_1[0xf] == '\x01') {
      param_1[3] = '\0';
      param_1[10] = '\0';
      param_1[0xc] = ' ';
      param_1[2] = '\x01';
      return 0;
    }
    if (*(int *)(param_2 + 0x30) == 1) {
      iVar2 = *(int *)(param_2 + 0x40);
      if (iVar2 < 1) {
        iVar2 = 1;
      }
      param_1[9] = (char)iVar2;
      param_1[0xd] = *(char *)(param_2 + 0x44);
      param_1[0xe] = *(char *)(param_2 + 0x10);
      param_1[0xb] = *(char *)(param_2 + 0x38);
      param_1[0x11] = *(char *)(param_2 + 0x4c);
      param_1[0x12] = *(char *)(param_2 + 0x50);
      return 0;
    }
    if (param_6 != 0) {
      param_1[0xc] = (param_7 != 4) * '\x04' + '\x04';
      return 0;
    }
  }
  else {
    param_1[8] = '\0';
    iVar2 = *(int *)(param_2 + 4);
    if (*(int *)(param_2 + 4) == 0) {
      iVar2 = DAT_00a37e70;
    }
    param_1[0xc] = (char)iVar2;
    param_1[0xd] = '\0';
    param_1[0xe] = '\0';
    param_1[0xb] = '\0';
    param_1[4] = '\x01';
    param_1[1] = '\0';
    param_1[0x10] = (char)param_6;
    param_1[5] = '\0';
    param_1[3] = param_1[0xf] == '\0';
    param_1[9] = '\0';
    param_1[0x11] = '\0';
    param_1[0x12] = '\0';
    param_1[10] = '\0';
  }
  return 0;
}

