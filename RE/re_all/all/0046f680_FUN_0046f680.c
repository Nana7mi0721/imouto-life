
int FUN_0046f680(int param_1,int param_2)

{
  int local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  while( true ) {
    if (*(char *)(param_1 + local_8) == '\0') {
      return 0;
    }
    if (((local_c == 0) && (DAT_0084b268 != 5)) &&
       (((0x80 < *(byte *)(param_1 + local_8) &&
         (((1 < DAT_0084b268 && (DAT_0084b268 < 5)) || (*(byte *)(param_1 + local_8) < 0xa0)))) ||
        ((0xdf < *(byte *)(param_1 + local_8) && (*(byte *)(param_1 + local_8) < 0xfd)))))) {
      local_c = 1;
    }
    else if ((local_c == 1) &&
            (((*(char *)(param_1 + local_8) != '\x7f' && (0x3f < *(byte *)(param_1 + local_8))) &&
             (*(byte *)(param_1 + local_8) < 0xfd)))) {
      local_c = 2;
    }
    else if (((local_c == 2) && (DAT_0084b268 != 5)) &&
            (((0x80 < *(byte *)(param_1 + local_8) &&
              (((1 < DAT_0084b268 && (DAT_0084b268 < 5)) || (*(byte *)(param_1 + local_8) < 0xa0))))
             || ((0xdf < *(byte *)(param_1 + local_8) && (*(byte *)(param_1 + local_8) < 0xfd))))))
    {
      local_c = 1;
    }
    else {
      local_c = 0;
    }
    if (local_8 == param_2) break;
    local_8 = local_8 + 1;
  }
  return local_c;
}

