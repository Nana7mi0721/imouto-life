
bool __fastcall FUN_00446ea0(int param_1)

{
  char cVar1;
  
  if (((*(int *)(param_1 + 0x40) == -1) &&
      (cVar1 = operator!=<>(param_1 + 8,&DAT_007ce9ef), cVar1 == '\0')) ||
     (*(char *)(param_1 + 0x53) != '\0')) {
    cVar1 = FUN_0044a350(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),0,
                         0xffffffff,*DAT_00a16694 + 1);
    return cVar1 != '\0';
  }
  return false;
}

