
int FUN_00575d10(uint param_1,uint param_2,undefined1 *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  undefined1 *puVar4;
  int iVar5;
  uint local_8;
  uint local_4;
  
  iVar2 = param_4;
  puVar4 = param_3;
  uVar1 = param_2;
  iVar5 = 0;
  local_8 = 0;
  local_4 = param_1;
  if (param_4 == 0) {
    return 0;
  }
  if ((int)param_2 < 0) {
    cVar3 = FUN_00573aa0(&local_4,&param_1,&local_8);
    while (cVar3 != '\0') {
      if ((param_1 < 0x100) && (1 < (uint)(iVar2 - iVar5))) {
        if (puVar4 != (undefined1 *)0x0) {
          *puVar4 = (char)param_1;
          puVar4 = puVar4 + 1;
        }
        iVar5 = iVar5 + 1;
      }
      cVar3 = FUN_00573aa0(&local_4,&param_1,&local_8);
    }
  }
  else {
    local_8 = 0;
    if (param_2 != 0) {
      do {
        cVar3 = FUN_00573aa0(&local_4,&param_1,&local_8);
        if (cVar3 == '\0') break;
        if ((param_1 < 0x100) && (1 < (uint)(iVar2 - iVar5))) {
          if (puVar4 != (undefined1 *)0x0) {
            *puVar4 = (char)param_1;
            puVar4 = puVar4 + 1;
          }
          iVar5 = iVar5 + 1;
        }
      } while (local_8 < uVar1);
    }
  }
  if (puVar4 != (undefined1 *)0x0) {
    *puVar4 = 0;
  }
  return iVar5 + 1;
}

