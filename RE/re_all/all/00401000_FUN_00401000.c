
int FUN_00401000(void)

{
  allocator<char> *this;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007a842b;
  local_10 = ExceptionList;
  if (DAT_00a0f7ec == 0) {
    ExceptionList = &local_10;
    this = operator_new(1);
    local_8 = 0;
    if (this == (allocator<char> *)0x0) {
      local_1c = 0;
    }
    else {
      local_1c = std::allocator<char>::allocator<char>(this);
    }
    DAT_00a0f7ec = local_1c;
  }
  ExceptionList = local_10;
  return DAT_00a0f7ec;
}

