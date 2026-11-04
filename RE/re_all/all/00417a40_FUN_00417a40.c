
byte * FUN_00417a40(byte *param_1,int param_2)

{
  if (((param_2 != 0) && (DAT_0084b268 != 5)) &&
     (((0x80 < *param_1 && (((1 < DAT_0084b268 && (DAT_0084b268 < 5)) || (*param_1 < 0xa0)))) ||
      ((0xdf < *param_1 && (*param_1 < 0xfd)))))) {
    param_1 = param_1 + 1;
  }
  if (*param_1 != 0) {
    param_1 = param_1 + 1;
  }
  return param_1;
}

