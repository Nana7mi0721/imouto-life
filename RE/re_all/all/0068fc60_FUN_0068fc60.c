
void FUN_0068fc60(int param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  
  iVar2 = *(int *)(param_1 + 0x17c);
  if (*(uint *)(iVar2 + 8) < *(uint *)(param_1 + 0x110)) {
    puVar1 = (uint *)(iVar2 + 0xc);
    while( true ) {
      if (*puVar1 < *(uint *)(param_1 + 0x10c)) {
        (**(code **)(*(int *)(param_1 + 0x180) + 4))
                  (param_1,param_2,param_3,param_4,iVar2 + 0x18,puVar1,*(uint *)(param_1 + 0x10c));
      }
      if (*puVar1 != *(uint *)(param_1 + 0x10c)) {
        return;
      }
      cVar3 = (**(code **)(*(int *)(param_1 + 0x184) + 4))(param_1,iVar2 + 0x18);
      if (cVar3 == '\0') break;
      if (*(char *)(iVar2 + 0x10) != '\0') {
        *param_3 = *param_3 + 1;
        *(undefined1 *)(iVar2 + 0x10) = 0;
      }
      *puVar1 = 0;
      uVar4 = *(int *)(iVar2 + 8) + 1;
      *(uint *)(iVar2 + 8) = uVar4;
      if (*(uint *)(param_1 + 0x110) <= uVar4) {
        return;
      }
    }
    if (*(char *)(iVar2 + 0x10) == '\0') {
      *param_3 = *param_3 + -1;
      *(undefined1 *)(iVar2 + 0x10) = 1;
    }
  }
  return;
}

