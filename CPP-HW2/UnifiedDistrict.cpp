#include "UnifiedDistrict.h"

UnifiedDistrict::UnifiedDistrict(char* name, int representativeNum) : District(name, representativeNum){}


void UnifiedDistrict::printType(std::ostream& os) const
{
	os << "District Type: Unified";
}

void UnifiedDistrict::printElectionResult(int partiesLogSize, Party** parties)
{
	Party* winningParty;
    const char* headName;
    winningParty = parties[this->getWinningParty()-1];
    headName = winningParty->getPartyHead()->getName();
    cout << "--- the winning party head --- " << endl;
    cout << "    head of the winning party- " << headName << endl
        << "    vote percentage- " << this->getVotePercentage() << "%" << endl;
    winningParty->increaseNumberOfWinningRepresentives(this->getRepresentativeNum());
	District::printElectionResult(partiesLogSize, parties);
}
void UnifiedDistrict::save(ostream& out) const
{
    out.write(rcastcc(DISTRICT_TYPE::divided), sizeof(DISTRICT_TYPE::divided));
    this->District::save(out);
}
