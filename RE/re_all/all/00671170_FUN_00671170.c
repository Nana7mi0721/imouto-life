
void FUN_00671170(int param_1,undefined4 *param_2)

{
  ushort uVar1;
  
  if (((param_1 != 0) && (param_2 != (undefined4 *)0x0)) &&
     ((*(uint *)(param_1 + 0x74) & 0x400) == 0)) {
    FUN_00677290(param_1);
    if (((*(uint *)(param_1 + 0x74) & 0x1000) != 0) && (*(int *)(param_1 + 0x268) != 0)) {
      FUN_006687b0(param_1,s_MNG_features_are_not_allowed_in_a_00a0c2a8);
      *(undefined4 *)(param_1 + 0x268) = 0;
    }
    FUN_006774b0(param_1,*param_2,param_2[1],*(undefined1 *)(param_2 + 6),
                 *(undefined1 *)((int)param_2 + 0x19),*(undefined1 *)((int)param_2 + 0x1a),
                 *(undefined1 *)((int)param_2 + 0x1b),*(undefined1 *)(param_2 + 7));
    if ((((*(ushort *)((int)param_2 + 0x72) & 0x8000) == 0) &&
        ((*(ushort *)((int)param_2 + 0x72) & 8) != 0)) && ((*(byte *)(param_2 + 2) & 1) != 0)) {
      FUN_00677ed0(param_1,param_2[10]);
    }
    uVar1 = *(ushort *)((int)param_2 + 0x72) & 0x8000;
    if ((uVar1 == 0) && ((param_2[2] & 0x1000) != 0)) {
      if ((param_2[2] & 0x800) != 0) {
        FUN_006689d0(param_1,s_profile_matches_sRGB_but_writing_00a0c814);
      }
      FUN_00677f40(param_1,param_2[0x1d],param_2[0x1e]);
    }
    else if ((uVar1 == 0) && ((param_2[2] & 0x800) != 0)) {
      FUN_00677f00(param_1,*(undefined2 *)(param_2 + 0x1c));
    }
    if ((*(byte *)(param_2 + 2) & 2) != 0) {
      FUN_00678520(param_1,param_2 + 0x25,*(undefined1 *)((int)param_2 + 0x19));
    }
    if ((((*(ushort *)((int)param_2 + 0x72) & 0x8000) == 0) &&
        ((*(ushort *)((int)param_2 + 0x72) & 0x10) != 0)) && ((*(byte *)(param_2 + 2) & 4) != 0)) {
      FUN_006785e0(param_1,param_2 + 0xb);
    }
    FUN_006712d0(param_1,param_2,1);
    *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 0x400;
  }
  return;
}

