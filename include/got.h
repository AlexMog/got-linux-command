#ifndef GOT_H_
# define GOT_H_

typedef struct s_quote {
  char *author;
  char *quote;
}t_quote;

t_quote got_quotes[] = {
  {"Ygritte", "You know nothing, Jon Snow."},
  {"Jaime Lannister", "Give my regards to the Night’s Watch. I’m sure it will be thrilling. And if it’s not, it’s only for life."},
  {"Eddard ‘Ned’ Stark", "War was easier than daughters."},
  {"Daenerys Targaryen", "I am a Khaleesi of the Dothraki. I am the wife of the great Kahl and I carry his son inside me. The next time you raise a hand to me will be the last time you have hands."},
  {"Tyrion Lannister", "A Lannister always pays his debts."},
  {"Eddard ‘Ned’ Stark", "The man who passes the sentence should swing the sword."},
  {"Tonny Stark", "I'm a Stark!"},
  {"Cersei Lannister", "When you play the game of thrones, you win or you die."},
  {"Tyrion Lannister", "I will hurt you for this. A day will come when you think you are safe and happy, and your joy will turn to ashes in your mouth. And you will know the debt is paid."},
  {"Daenerys Targaryen", "A dragon is not a slave."},
  {"Tyrion Lannister", "And now I’ve struck a king. Did my hand fall from my wrist?"},
  {"Catelyn Stark", "Wise men do not make demands of kings."},
  {"Margaery Tyrell", "I want to be THE queen."},
  {"Cersei Lannister", "If you ever call me sister again I’ll have you strangled in your sleep."},
  {"Tywin Lannister", "Any man who must say, I am the king, is no true king."},
  {"Almost everyone", "Winter is comming..."},
  {"Jon Snow to Samwell Tarly", "The first Lord Commander in history to sacrifice the lives of sworn brothers to save the lives of wildlings. How’s it feel to be friends with the most hated man at Castle Black?"},
  {"Samwell Tarly", "The last thing I’ll see in this world will be the look in her eyes when I failed then"},
  {"Jon Snow", "I’m glad the end of the world’s working out well for someone."},
  {"Stannis Baratheon", "Go and do your duty."},
  {"Sansa Stark", "I know what Ramsay is. I know what he’ll do to me. If I’m going to die, let it happen while there’s still some of me left."},
  {"Arya Stark", "You know who I am. I’m Arya Stark. Do you know who you are? You’re no one. You’re nothing."},
  {"Jamie Lannister", "I’m glad Trystane’s coming with us, he seems like a nice boy. You’re lucky. Arranged marriages are rarely so well arranged."},
  {"Jamie Lannister", "We don’t choose whom we love. It just, well, it’s behind out control."},
  {"Tyrion Lannister", "You love her, don’t you? How could you not? Of course it’s hopeless for the both of you, a sellsword from the fighting pits and a disgraced knight. Neither one of you is fit consort for a queen, but we always want the wrong woman."},
  {"Tyrion Lannister", "My Valyrian is a bit nostril."},
  {"Jorah to Tyrion", "If I ever kill you, your eyes will be wide open."},
  {"Daario about Grey Worm", "He’s the toughest man with no balls I ever met."},
  {"Varys", "Information is the key. You need to learn your enemies’ strengths and strategies. You need to learn which of your friends are not your friends."},
  {"Qyburn to Cersei Lannister about the newest member of the Kingsguard", "He has taken a holy vow of silence. He’s sworn that he will not speak until all his grace’s enemies are dead and the evil has been driven from the realm."},
  {"Alliser Thorne and others to Jon while stabbing him", "For the Watch."}
};

int get_random(int, int);

#endif /* !GOT_H_ */
