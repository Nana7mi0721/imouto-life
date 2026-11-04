
undefined4 FUN_004ec110(int *param_1)

{
  ctype<char> *this;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b149b;
  local_10 = ExceptionList;
  if ((param_1 != (int *)0x0) && (*param_1 == 0)) {
    ExceptionList = &local_10;
    this = operator_new(0x18);
    local_8 = 0;
    if (this == (ctype<char> *)0x0) {
      local_1c = 0;
    }
    else {
      local_1c = std::ctype<char>::ctype<char>(this,(short *)0x0,false,0);
    }
    *param_1 = local_1c;
  }
  ExceptionList = local_10;
  return 2;
}

