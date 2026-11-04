
undefined4 FUN_0042ee40(int param_1,char param_2,undefined *param_3)

{
  int local_c;
  undefined *local_8;
  
  if (param_3 == (undefined *)0x0) {
    local_8 = &DAT_00a18178;
  }
  else {
    local_8 = param_3;
  }
  if (param_2 == '\0') {
    if (param_1 == 0) {
      local_c = *(int *)(local_8 + 0x9c8);
    }
    if (param_1 == 1) {
      local_c = *(int *)(local_8 + 0x9cc);
    }
    if (param_1 == 2) {
      local_c = *(int *)(local_8 + 0x9d0);
    }
    if (local_c == 0x10) {
      return 0x12d;
    }
    if (local_c == 0x20) {
      return 0x12e;
    }
    if (local_c == 0x40) {
      return 0x12f;
    }
    if (local_c == 0x80) {
      return 0x130;
    }
    if (local_c == 0x100) {
      return 0x131;
    }
    if (local_c == 0x200) {
      return 0x132;
    }
    if (local_c == 0x400) {
      return 0x133;
    }
    if (local_c == 0x800) {
      return 0x134;
    }
    if (local_c == 0x1000) {
      return 0x135;
    }
    if (local_c == 0x2000) {
      return 0x136;
    }
    if (local_c == 0x4000) {
      return 0x137;
    }
    if (local_c == 0x8000) {
      return 0x138;
    }
    if (local_c == 0x10000) {
      return 0x139;
    }
    if (local_c == 0x20000) {
      return 0x13a;
    }
    if (local_c == 0x40000) {
      return 0x13b;
    }
  }
  else {
    if (param_1 == 0) {
      return *(undefined4 *)(local_8 + 0x9bc);
    }
    if (param_1 == 1) {
      return *(undefined4 *)(local_8 + 0x9c0);
    }
    if (param_1 == 2) {
      return *(undefined4 *)(local_8 + 0x9c4);
    }
  }
  return 0;
}

