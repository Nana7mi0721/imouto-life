
int FUN_005746c0(undefined4 param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  uint local_8;
  undefined4 local_4;
  
  uVar2 = param_4;
  puVar4 = param_3;
  uVar1 = param_2;
  iVar5 = 0;
  local_8 = 0;
  local_4 = param_1;
  if (param_4 < 4) {
    return 0;
  }
  if ((int)param_2 < 0) {
    cVar3 = FUN_00573aa0(&local_4,&param_1,&local_8);
    while (cVar3 != '\0') {
      if (7 < uVar2 - iVar5) {
        if (puVar4 != (undefined4 *)0x0) {
          *(char *)puVar4 = (char)param_1;
          *(char *)((int)puVar4 + 1) = (char)((uint)param_1 >> 8);
          *(char *)((int)puVar4 + 2) = (char)((uint)param_1 >> 0x10);
          *(char *)((int)puVar4 + 3) = (char)((uint)param_1 >> 0x18);
          puVar4 = puVar4 + 1;
        }
        iVar5 = iVar5 + 4;
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
        if (7 < uVar2 - iVar5) {
          if (puVar4 != (undefined4 *)0x0) {
            *(char *)puVar4 = (char)param_1;
            *(char *)((int)puVar4 + 1) = (char)((uint)param_1 >> 8);
            *(char *)((int)puVar4 + 2) = (char)((uint)param_1 >> 0x10);
            *(char *)((int)puVar4 + 3) = (char)((uint)param_1 >> 0x18);
            puVar4 = puVar4 + 1;
          }
          iVar5 = iVar5 + 4;
        }
      } while (local_8 < uVar1);
    }
  }
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0;
  }
  return iVar5 + 4;
}

