
int FUN_004f86b0(char *param_1,undefined1 *param_2)

{
  char cVar1;
  ushort uVar2;
  undefined1 auStack_8 [2];
  undefined2 local_6;
  
  while( true ) {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = CONCAT11(cVar1,*param_2);
    param_2 = param_2 + 1;
    if (('`' < cVar1) && (cVar1 < '{')) {
      _auStack_8 = CONCAT13(cVar1 + -0x20,(uint3)uVar2 << 0x10);
      uVar2 = local_6;
    }
    local_6 = uVar2;
    if (('`' < (char)local_6) && ((char)local_6 < '{')) {
      local_6 = CONCAT11(local_6._1_1_,(char)local_6 + -0x20);
    }
    if (local_6._1_1_ == '\0') {
      return -(uint)((char)local_6 != '\0');
    }
    if ((char)local_6 == '\0') {
      return 1;
    }
    if (local_6._1_1_ < (char)local_6) break;
    if ((char)local_6 < local_6._1_1_) {
      return 1;
    }
  }
  return -1;
}

