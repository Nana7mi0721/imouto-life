
int FUN_00575c20(undefined4 param_1,uint param_2,undefined1 *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  uint local_c;
  undefined4 local_8;
  int local_4;
  
  iVar2 = param_4;
  uVar1 = param_2;
  local_4 = 0;
  local_c = 0;
  local_8 = param_1;
  if (param_4 == 0) {
    return 0;
  }
  if ((int)param_2 < 0) {
    cVar3 = FUN_00573a20(&local_8,&param_1,&local_c);
    while (cVar3 != '\0') {
      FUN_00573cc0(&param_3,&param_1,&local_4,iVar2);
      cVar3 = FUN_00573a20(&local_8,&param_1,&local_c);
    }
  }
  else {
    local_c = 0;
    if (param_2 != 0) {
      do {
        cVar3 = FUN_00573a20(&local_8,&param_1,&local_c);
        if (cVar3 == '\0') break;
        FUN_00573cc0(&param_3,&param_1,&local_4,iVar2);
      } while (local_c < uVar1);
    }
  }
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = 0;
  }
  return local_4 + 1;
}

