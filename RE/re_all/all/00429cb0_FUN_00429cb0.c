
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_00429cb0(char param_1,char param_2,int *param_3,int param_4)

{
  char acStackY_170 [80];
  undefined4 uStackY_120;
  int local_110;
  char local_10c [260];
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  if (param_1 != '\0') {
    *param_3 = 0;
  }
  uStackY_120 = 0x429ce8;
  _memcpy(local_10c,&DAT_00a146a0,0x100);
  if ((param_4 < 100) || (0x163 < param_4)) {
    for (local_110 = 2; local_110 < 0x93; local_110 = local_110 + 1) {
      if ((((((local_10c[local_110] == '\x01') && (local_110 != 0x1c)) && (local_110 != 1)) &&
           ((local_110 != 0x2a && (local_110 != 0x36)))) &&
          ((local_110 != 0xe && ((local_110 != 0x39 && (local_110 != 0x3a)))))) &&
         (local_110 != 0x70)) {
        if (local_110 == 0x9c) {
          local_110 = 0x1c;
        }
        if ((param_1 == '\0') && (param_2 == '\0')) {
          return local_110 + 100;
        }
        if (*param_3 == local_110) {
          return 0;
        }
        if (param_1 == '\0') {
          *param_3 = 0;
        }
        else {
          *param_3 = local_110;
        }
        return local_110 + 100;
      }
    }
    *param_3 = 0;
    param_4 = 0;
  }
  else if (acStackY_170[param_4] != '\x01') {
    param_4 = 0;
  }
  return param_4;
}

