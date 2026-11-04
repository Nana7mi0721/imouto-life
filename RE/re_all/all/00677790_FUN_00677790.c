
void FUN_00677790(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  
  uVar2 = param_3;
  iVar1 = param_1;
  if ((((*(byte *)(param_1 + 0x268) & 1) == 0) && (param_3 == 0)) || (0x100 < param_3)) {
    pcVar4 = s_Invalid_number_of_colors_in_pale_00a0d44c;
    if (*(char *)(param_1 + 0x157) != '\x03') goto LAB_006777d6;
    FUN_00668620(param_1,s_Invalid_number_of_colors_in_pale_00a0d44c);
  }
  if ((*(byte *)(iVar1 + 0x157) & 2) != 0) {
    *(short *)(iVar1 + 0x148) = (short)uVar2;
    FUN_00677300(iVar1,0x504c5445,uVar2 * 3);
    if (uVar2 != 0) {
      puVar3 = (undefined1 *)(param_2 + 2);
      do {
        param_1._0_3_ = CONCAT12(*puVar3,*(undefined2 *)(puVar3 + -2));
        FUN_00677370(iVar1,&param_1,3);
        puVar3 = puVar3 + 3;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    FUN_006773b0(iVar1);
    *(uint *)(iVar1 + 0x74) = *(uint *)(iVar1 + 0x74) | 2;
    return;
  }
  pcVar4 = s_Ignoring_request_to_write_a_PLTE_00a0d414;
LAB_006777d6:
  FUN_006687b0(iVar1,pcVar4);
  return;
}

